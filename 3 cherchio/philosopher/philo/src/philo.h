/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:51:37 by andrea            #+#    #+#             */
/*   Updated: 2024/07/08 14:17:24 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>

# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define YELLOW	"\033[1;33m"
# define MAGEN	"\033[1;35m"

# define P_EAT "\033[1;32mis eating 🍝\033[0m"
# define P_SLEEP "\033[1;34mis sleeping 🌙\033[0m"
# define P_THINK "\033[1;35mis thinking 💭\033[0m"
# define P_FORK "\033[1;33mhas taken a fork 🍴\033[0m"
# define P_DIE "\033[1;31mdied 💀\033[0m"

typedef struct s_data	t_data;

typedef struct s_fork
{
	pthread_mutex_t	fork_id;
	int				f_index;
}				t_fork;

typedef struct s_philo
{
	int				index;
	int				nbr_meal;
	pthread_t		philo_id;
	long			last_meal;
	bool			finish;
	t_fork			*sec_fork;
	t_fork			*first_fork;
	t_data			*data;
}					t_philo;

typedef struct s_data
{
	long			philo_eat;
	long			n_philo;
	long			tidie;
	long			tieat;
	long			tisl;
	long			nbr_mls;
	bool			end_sim;
	long int		start;
	int				nbr_done;
	bool			all_done;
	t_philo			*philos;
	t_fork			*forks;
	pthread_t		t_monitor;
	pthread_mutex_t	m_all_done;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_dead;
}		t_data;

char		*ft_itoa(int n);
long		ft_atoi(const char *nptr, int i);
int			ft_parse(t_data *data, char **argv);
int			ft_init(t_data *data);
long long	gettime(void);
void		*routine(void *arg);
void		ft_usleep(int ms);
void		print_action(long time, int p_index, char *action, t_philo *philo);
int			is_dead(t_philo *philo, int i);
void		*check_death(void *arg);
void		spinlock(t_data *data);
bool		set_bool(pthread_mutex_t *mutex, bool *value, bool new_value);
bool		get_bool(pthread_mutex_t *mutex, bool *value);
int			set_int(pthread_mutex_t *mutex, int *value, int new_value);
int			get_int(pthread_mutex_t *mutex, int *value);
#endif
