/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:51:21 by melee             #+#    #+#             */
/*   Updated: 2023/06/20 12:12:11 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_sem_parent(t_param *ptr, int philo_no)
{
	ptr->write = sem_open("write", O_CREAT, 0644, 1);
	ptr->fork = sem_open("fork", O_CREAT, 0644, philo_no);
}

void	init_sem_child(t_param *ptr, t_philo *philo)
{
	char *eat_die;
	
	eat_die = ft_itoa(philo->philo_no);
	ptr->write = sem_open("write", 0);
	ptr->fork = sem_open("fork", 0);
	philo->eat_die = sem_open(eat_die, O_CREAT, 0644, 1);
	free(eat_die);
}

int	init(t_param *ptr, int argc, char **argv)
{	
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200
		|| ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0)
		return (0);
	if (argc == 6)
		if (ft_atoi(argv[5]) <= 0)
			return (0);
	ptr->philo_no = 0;
	ptr->t_to_die = ft_atoi(argv[2]);
	ptr->t_to_eat = ft_atoi(argv[3]);
	ptr->t_to_sleep = ft_atoi(argv[4]);
	init_sem_parent(ptr, ft_atoi(argv[1]));
	if (argc == 5)
		ptr->num_to_eat = -1;
	else
		ptr->num_to_eat = ft_atoi(argv[5]);
	gettimeofday(&ptr->start_time, NULL);
	return (1);
}

void	init_philo(t_param *ptr, t_philo *philo)
{
	philo->philo_no = ptr->philo_no;
	if (timestamp(ptr) > 0)
		gettimeofday(&ptr->start_time, NULL);
	philo->t_last_eat = 0;
	philo->ate = 0;
	philo->died = 0;
	init_sem_child(ptr, philo);
}
