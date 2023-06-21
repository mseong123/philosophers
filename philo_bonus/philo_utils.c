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

void	exec_wait_kill(t_param *ptr, char **argv)
{
	int	i;

	i = 0;
	if (ptr->num_to_eat != -1)
		while (i++ < ptr->num_to_eat)
		{
			waitpid(-1, &ptr->exit_status, 0);
			if (WIFEXITED(ptr->exit_status) && WEXITSTATUS(ptr->exit_status) == 1)
				kill_all_process(ptr, argv);
		}
	else
		waitpid(-1, NULL, 0);
		kill_all_process(ptr, argv);
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
	}
	if (!ft_strcmp(str, "sleeping"))
		printf("%d %d is sleeping\n", timestamp(ptr), philo->philo_no);
	if (!ft_strcmp(str, "thinking"))
		printf("%d %d is thinking\n", timestamp(ptr), philo->philo_no);
	if (!ft_strcmp(str, "died"))
	{
		printf("%d %d died\n", timestamp(ptr), philo->philo_no);
		exit(1);
	}
}

void	display(t_param *ptr, t_philo *philo, char *str)
{
	sem_wait(ptr->write);
	if (!philo->died)
	{
		if ((ptr->num_to_eat != -1 && philo->ate != ptr->num_to_eat)
			|| ptr->num_to_eat == -1)
			display_sub(ptr, philo, str);
	}
	sem_post(ptr->write);
}
