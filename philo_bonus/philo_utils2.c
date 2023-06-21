/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:20:43 by melee             #+#    #+#             */
/*   Updated: 2023/06/21 17:21:01 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_all_process(t_param *ptr, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		kill(ptr->process[i], SIGKILL);
		i++;
	}
}

void	mod_usleep(int time, t_param *ptr)
{
	int	i;
	int	j;

	i = timestamp(ptr);
	j = 0;
	while (j < time)
	{
		j = timestamp(ptr) - i;
		usleep(50);
	}
}
