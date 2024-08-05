/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:43:00 by aconciar          #+#    #+#             */
/*   Updated: 2024/07/08 14:19:38 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(long time, int p_index, char *action, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	pthread_mutex_lock(&philo->data->m_dead);
	if (philo->data->end_sim == false)
		printf("%ld %d %s\n", time, p_index, action);
	pthread_mutex_unlock(&philo->data->m_dead);
	pthread_mutex_unlock(&philo->data->m_print);
}

static void	ft_sleep(t_philo *philo)
{
	print_action(gettime() - philo->data->start, philo->index, P_SLEEP, philo);
	ft_usleep(philo->data->tisl);
}

static void	ft_think(t_philo *philo)
{
	print_action(gettime() - philo->data->start, philo->index, P_THINK, philo);
}

static void	ft_eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->first_fork->fork_id);
	print_action(gettime() - philo->data->start, philo->index, P_FORK, philo);
	if (philo->data->n_philo == 1)
	{
		ft_usleep(philo->data->tidie * 2);
		pthread_mutex_unlock(&philo->first_fork->fork_id);
		return ;
	}
	pthread_mutex_lock(&philo->sec_fork->fork_id);
	print_action(gettime() - philo->data->start, philo->index, P_FORK, philo);
	print_action(gettime() - philo->data->start, philo->index, P_EAT, philo);
	pthread_mutex_lock(&(philo->data->m_eat));
	philo->last_meal = gettime();
	philo->nbr_meal++;
	pthread_mutex_unlock(&(philo->data->m_eat));
	ft_usleep(philo->data->tieat);
	pthread_mutex_unlock(&philo->first_fork->fork_id);
	pthread_mutex_unlock(&philo->sec_fork->fork_id);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 0)
		ft_usleep(philo->data->tieat / 10);
	while (!is_dead(philo, 0))
	{
		ft_eat(philo);
		if (philo->nbr_meal == philo->data->nbr_mls)
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	philo->finish = true;
	spinlock(philo->data);
	return (NULL);
}
