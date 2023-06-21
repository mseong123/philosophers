/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:33:24 by melee             #+#    #+#             */
/*   Updated: 2023/06/20 14:16:19 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_param *ptr, t_philo *philo)
{
	sem_wait(ptr->fork);
	display(ptr, philo, "fork");
	sem_wait(ptr->fork);
	display(ptr, philo, "fork");
	sem_wait(philo->eat_die);
	philo->t_last_eat = timestamp(ptr);
	sem_post(philo->eat_die);
	display(ptr, philo, "eating");
	mod_usleep(ptr->t_to_eat, ptr);
	sem_post(ptr->fork);
	sem_post(ptr->fork);
}

void	philo_sleep(t_param *ptr, t_philo *philo)
{
	display(ptr, philo, "sleeping");
	mod_usleep(ptr->t_to_sleep, ptr);
}

void	think(t_param *ptr, t_philo *philo)
{
	display(ptr, philo, "thinking");
}

void	*check_died(void *arg)
{
	int	i;
	t_param	*ptr;

	ptr = (t_param *)arg;
	while (!ptr->philo->died)
	{
		if (ptr->num_to_eat != -1 && ptr->philo->ate == ptr->num_to_eat)
			exit(0);
		i = 0;
		while (i < ptr->philo_no)
		{
			sem_wait(ptr->philo->eat_die);
			if ((timestamp(ptr) - ptr->philo->t_last_eat)
				> ptr->t_to_die)
				display(ptr, ptr->philo, "died");
			sem_post(ptr->philo->eat_die);
			i++;
		}
		
	}
	return (NULL);
}
