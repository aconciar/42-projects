/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:52:36 by andrea            #+#    #+#             */
/*   Updated: 2024/06/25 22:46:30 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup(t_data *data, int error)
{
	int	i;

	i = -1;
	if (error)
		write(2, RED "Error\n" RST, 25);
	while (++i < data->n_philo)
		pthread_mutex_destroy(&data->forks[i].fork_id);
	free(data->forks);
	free(data->philos);
	free(data);
}

static int	start_simulation(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_create(&data->philos[i].philo_id,
				NULL, routine, &data->philos[i]) != 0)
			return (cleanup(data, 1), 1);
		if (pthread_create(&data->t_monitor, NULL,
				check_death, &data->philos[i]) != 0)
			return (cleanup(data, 1), 1);
		if (pthread_detach(data->t_monitor) != 0)
			return (cleanup(data, 1), 1);
	}
	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_join(data->philos[i].philo_id, NULL) != 0)
			return (cleanup(data, 1), 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if ((argc != 5 && argc != 6) || (ft_parse(data, argv)) || (ft_init(data)))
	{
		free(data);
		return (write(2, RED "Invalid Arguments\n" RST, 25));
	}
	if (data->nbr_mls == 0)
		return (cleanup(data, 1), 1);
	else
		start_simulation(data);
	cleanup(data, 0);
	return (0);
}
