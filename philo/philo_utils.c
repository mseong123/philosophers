/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:06:57 by melee             #+#    #+#             */
/*   Updated: 2023/06/20 12:22:40 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timestamp(t_param *ptr)
{
	struct timeval	current;
	int				res;

	gettimeofday(&current, NULL);
	res = ((current.tv_sec - ptr->start_time.tv_sec) * 1000) \
		+ ((current.tv_usec - ptr->start_time.tv_usec) / 1000);
	return (res);
}

void	thread_join(t_param *ptr, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
		pthread_join(ptr->thread[i++], NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

void	display_sub(t_param *ptr, t_philo *philo, char *str)
{
	if (!ft_strcmp(str, "fork"))
		printf("%d %d has taken a fork\n", timestamp(ptr), philo->philo_no);
	if (!ft_strcmp(str, "eating"))
	{
		printf("%d %d is eating\n", timestamp(ptr), philo->philo_no);
		philo->ate++;
		check_fully_ate(ptr, philo);
	}
	if (!ft_strcmp(str, "sleeping"))
		printf("%d %d is sleeping\n", timestamp(ptr), philo->philo_no);
	if (!ft_strcmp(str, "thinking"))
		printf("%d %d is thinking\n", timestamp(ptr), philo->philo_no);
	if (!ft_strcmp(str, "died"))
	{
		printf("%d %d died\n", timestamp(ptr), philo->philo_no);
		ptr->any_died = 1;
	}
}

void	display(t_param *ptr, t_philo *philo, char *str)
{
	pthread_mutex_lock(&ptr->write);
	if (!ptr->any_died)
	{
		if ((ptr->num_to_eat != -1 && ptr->num_fully_ate != ptr->philo_no)
			|| ptr->num_to_eat == -1)
			display_sub(ptr, philo, str);
	}
	pthread_mutex_unlock(&ptr->write);
}
