/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 08:47:32 by melee             #+#    #+#             */
/*   Updated: 2023/06/20 12:24:43 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_process(t_param *ptr)
{
	t_philo	philo;

	init_philo(ptr, &philo);
	ptr->philo = &philo;
	pthread_create(&philo.thread, NULL, check_died, ptr);
	while (1)
	{
		eat(ptr, &philo);
		philo_sleep(ptr, &philo);
		think(ptr, &philo);
	}
}

int	main(int argc, char **argv)
{
	t_param	ptr;
	int		i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (!init(&ptr, argc, argv))
		{
			printf("Wrong parameter values used\n");
			return (EXIT_SUCCESS);
		}
		if (ft_atoi(argv[1]) == 1)
		{
			printf("%d %d died\n", ft_atoi(argv[2]), 1);
			return (EXIT_SUCCESS);
		}
		while (i < ft_atoi(argv[1]))
		{
			ptr.philo_no++;
			ptr.process[i] = fork();
			if (ptr.process[i] == 0)
				start_process(&ptr);
			i++;
		}
		wait_kill(&ptr, argv);
	}
	else
		printf("Incorrect no. of parameters\n");
	return (EXIT_SUCCESS);
}
