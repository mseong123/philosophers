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

static void	init_mutex(t_param *ptr, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
		pthread_mutex_init(&ptr->fork[i++], NULL);
	pthread_mutex_init(&ptr->init_lock, NULL);
	pthread_mutex_init(&ptr->eat_die, NULL);
	pthread_mutex_init(&ptr->write, NULL);
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
	ptr->philo_no = ft_atoi(argv[1]);
	ptr->decrem_philo = ft_atoi(argv[1]);
	ptr->t_to_die = ft_atoi(argv[2]);
	ptr->t_to_eat = ft_atoi(argv[3]);
	ptr->t_to_sleep = ft_atoi(argv[4]);
	init_mutex(ptr, argv);
	if (argc == 5)
		ptr->num_to_eat = -1;
	else
		ptr->num_to_eat = ft_atoi(argv[5]);
	ptr->any_died = 0;
	ptr->num_fully_ate = 0;
	gettimeofday(&ptr->start_time, NULL);
	return (1);
}

void	init_philo(t_param *ptr, t_philo *philo)
{
	pthread_mutex_lock(&ptr->init_lock);
	ptr->decrem_philo--;
	philo->philo_no = ptr->philo_no - ptr->decrem_philo;
	if (timestamp(ptr) > 0)
		gettimeofday(&ptr->start_time, NULL);
	philo->t_last_eat = 0;
	pthread_mutex_unlock(&ptr->init_lock);
}
