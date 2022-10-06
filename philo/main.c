/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:50:25 by aabeid            #+#    #+#             */
/*   Updated: 2022/06/12 14:31:31 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linker.h"

t_vars	initilizer(char **av, int ac)
{
	t_vars	philo;
	int		i;
	int		must_eat;

	i = 0;
	pthread_mutex_init(&philo.print, NULL);
	philo.status = NULL;
	philo.their_number = ft_atoi(av[1]);
	philo.time_to_die = ft_atoi(av[2]) * 1000;
	philo.time_to_eat = ft_atoi(av[3]) * 1000;
	philo.time_to_sleep = ft_atoi(av[4]) * 1000;
	philo.start_time = get_time();
	philo.clock = 0;
	must_eat = -1;
	if (ac == 6)
		must_eat = ft_atoi(av[5]);
	while (i < philo.their_number)
	{
		ft_lstadd_back(&philo.status, ft_lstnew(i + 1, must_eat));
		i++;
	}
	philo.status -> prev = ft_lstlast(philo.status);
	ft_lstlast(philo.status)->next = philo.status;
	return (philo);
}

int	main(int ac, char **av)
{
	t_vars	philo;

	if (ac < 5 || ac > 6 || input_checker(av, ac) == 0)
		return (0);
	philo = initilizer(av, ac);
	philosophers_creator(&philo);
	return (0);
}
