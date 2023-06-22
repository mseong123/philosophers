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
# define SNAME "fork"

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_philo
{
	int			philo_no;
	int			t_last_eat;
	int			ate;
	int			died;
	pthread_t	thread;
	sem_t		*eat_die;
}	t_philo;

typedef struct s_param
{
	int				philo_no;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				num_to_eat;
	struct timeval	start_time;
	sem_t			*write;
	sem_t			*fork;
	int				process[200];
	int				exit_status;
	t_philo			*philo;
}	t_param;

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		timestamp(t_param *ptr);
int		init(t_param *ptr, int argc, char **argv);
void	init_philo(t_param *ptr, t_philo *philo);
void	display(t_param *ptr, t_philo *philo, char *str);
void	*check_died(void *arg);
void	eat(t_param *ptr, t_philo *philo);
void	philo_sleep(t_param *ptr, t_philo *philo);
void	think(t_param *ptr, t_philo *philo);
void	mod_usleep(int time, t_param *ptr);
void	kill_all_process(t_param *ptr, char **argv);
void	mod_usleep(int time, t_param *ptr);
void	wait_kill(t_param *ptr, char **argv);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
