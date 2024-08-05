/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:18:06 by aconciar          #+#    #+#             */
/*   Updated: 2024/07/08 14:19:57 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	nbr_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_all_done);
	philo->data->nbr_done++;
	if (philo->data->nbr_done == philo->data->n_philo)
		philo->data->all_done = true;
	pthread_mutex_unlock(&philo->data->m_all_done);
}

int	is_dead(t_philo *philo, int i)
{
	int	result;

	pthread_mutex_lock(&philo->data->m_dead);
	if (i)
		philo->data->end_sim = true;
	result = philo->data->end_sim;
	pthread_mutex_unlock(&philo->data->m_dead);
	return (result);
}

int	is_full(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->data->m_dead);
	result = 0;
	if (philo->data->nbr_mls != -1 && philo->nbr_meal >= philo->data->nbr_mls)
		result = 1;
	pthread_mutex_unlock(&philo->data->m_dead);
	return (result);
}

void	*check_death(void *arg)
{
	t_philo	*phi;

	phi = (t_philo *)arg;
	ft_usleep(phi->data->tidie + 1);
	pthread_mutex_lock(&phi->data->m_eat);
	pthread_mutex_lock(&phi->data->m_stop);
	if (!is_dead(phi, 0) && gettime() - phi->last_meal >= (phi->data->tidie)
		&& phi->finish == false)
	{
		pthread_mutex_unlock(&phi->data->m_eat);
		pthread_mutex_unlock(&phi->data->m_stop);
		print_action(gettime() - phi->data->start, phi->index, P_DIE, phi);
		is_dead(phi, 1);
		nbr_done(phi);
		return (NULL);
	}
	pthread_mutex_unlock(&phi->data->m_eat);
	pthread_mutex_unlock(&phi->data->m_stop);
	nbr_done(phi);
	return (NULL);
}
