/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:08:40 by andrea            #+#    #+#             */
/*   Updated: 2024/07/08 14:18:00 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parse(t_data *data, char **argv)
{
	data->n_philo = ft_atoi(argv[1], 0);
	data->tidie = ft_atoi(argv[2], 0);
	data->tieat = ft_atoi(argv[3], 0);
	data->tisl = ft_atoi(argv[4], 0);
	if (data->n_philo == 0 || data->n_philo < 0 || data->n_philo > INT_MAX
		|| data->tidie == 0 || data->tidie < 0 || data->tidie > INT_MAX
		|| data->tieat == 0 || data->tieat < 0 || data->tieat > INT_MAX
		|| data->tisl == 0 || data->tisl < 0 || data->tisl > INT_MAX)
		return (1);
	if (argv[5])
	{
		data->nbr_mls = ft_atoi(argv[5], 0);
		if (data->nbr_mls == 0 || data->nbr_mls < 0 || data->nbr_mls > INT_MAX)
			return (1);
	}
	else
		data->nbr_mls = -1;
	return (0);
}

void	assing_forks(t_philo *philo, t_fork *forks, int i)
{
	if (i == philo->data->n_philo - 1)
	{
		philo->first_fork = &forks[0];
		philo->sec_fork = &forks[i];
	}
	else
	{
		philo->first_fork = &forks[i];
		philo->sec_fork = &forks[i + 1];
	}
}

static void	philo_init(t_data *data)
{
	int	i;

	data->start = gettime();
	i = -1;
	while (++i < data->n_philo)
	{
		data->philos[i].index = i + 1;
		data->philos[i].last_meal = 0;
		data->philos[i].sec_fork = NULL;
		data->philos[i].data = data;
		data->philos[i].finish = false;
		data->philos[i].nbr_meal = 0;
		assing_forks(&data->philos[i], data->forks, i);
	}
}

int	ft_init(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->m_print, NULL);
	pthread_mutex_init(&data->m_stop, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	pthread_mutex_init(&data->m_dead, NULL);
	pthread_mutex_init(&data->m_all_done, NULL);
	data->nbr_done = 0;
	data->all_done = false;
	data->end_sim = false;
	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	data->forks = malloc(sizeof(t_fork) * data->n_philo);
	if (!data->philos || !data->forks)
		return (1);
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i].fork_id, NULL) != 0)
			return (1);
		data->forks[i].f_index = i;
		i++;
	}
	philo_init(data);
	return (0);
}
