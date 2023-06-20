/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 08:48:06 by melee             #+#    #+#             */
/*   Updated: 2023/06/20 12:17:38 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philo
{
	int	philo_no;
	int	t_last_eat;
	int	ate;
}	t_philo;

typedef struct s_param
{
	int					philo_no;
	int					decrem_philo;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					num_to_eat;
	int					any_died;
	int					num_fully_ate;
	struct timeval		start_time;
	pthread_mutex_t		init_lock;
	pthread_mutex_t		eat_die;
	pthread_mutex_t		write;
	pthread_t			thread[200];
	t_philo				*philo[200];
	pthread_mutex_t		fork[200];
}	t_param;

int		ft_atoi(const char *str);
int		timestamp(t_param *ptr);
int		init(t_param *ptr, int argc, char **argv);
void	init_philo(t_param *ptr, t_philo *philo);
void	thread_join(t_param *ptr, char **argv);
void	display(t_param *ptr, t_philo *philo, char *str);
void	check_died(t_param *ptr);
void	eat(t_param *ptr, t_philo *philo);
void	philo_sleep(t_param *ptr, t_philo *philo);
void	think(t_param *ptr, t_philo *philo);
void	mod_usleep(int time, t_param *ptr);
void	check_fully_ate(t_param *ptr, t_philo *philo);

#endif
