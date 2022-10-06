/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:52:47 by aabeid            #+#    #+#             */
/*   Updated: 2022/09/27 12:22:17 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	forks_on(t_vars *p, t_status *is_eating, int on)
{
	if (on == 1)
	{
		pthread_mutex_lock(&is_eating->prev->rfork);
		pthread_mutex_lock(&is_eating->lfork);
		// pthread_mutex_lock(&p->print);
		// printf("%i %i has taken a fork\n", p->clock, is_eating->idx);
		// pthread_mutex_unlock(&p->print);
		pthread_mutex_lock(&is_eating->next->lfork);
		pthread_mutex_lock(&is_eating->rfork);
		is_eating->lf = 1;
		is_eating->rf = 1;
		printer(p->clock, is_eating->idx, "has taken a fork", p);
		printer(p->clock, is_eating->idx, "has taken a fork", p);
		//pthread_mutex_lock(&p->print);
		//printf("%i %i has taken a fork\n", p->clock, is_eating->idx);
		//pthread_mutex_unlock(&p->print);
	}
	if (on == 0)
	{
		pthread_mutex_unlock(&is_eating->prev->rfork);
		pthread_mutex_unlock(&is_eating->next->lfork);
		pthread_mutex_unlock(&is_eating->rfork);
		pthread_mutex_unlock(&is_eating->lfork);
		is_eating->rf = 0;
		is_eating->lf = 0;
	}
}

int	behavior_manager(t_vars *philo, t_status *status)
{
	while (status->must_eat != 0)
	{
		eating(philo, status);
		sleeping_and_thinking(philo, status);
		status->must_eat--;
	}
	return (0);
}

void	*routine(void *philo)
{
	t_vars	*temp;

	temp = (t_vars *)philo;
	behavior_manager(temp, temp->status);
	return (NULL);
}

void	philosophers_creator(t_vars *philo)
{
	pthread_t	*th;
	int			i;

	i = 0;
	th = malloc(philo->their_number * sizeof(pthread_t));
	while (i < philo->their_number)
	{
		pthread_create(&th[i++], NULL, routine, philo);
		usleep(50);
		philo->status = philo->status->next;
	}
	while (philo->status->must_eat != 0)
	{
		if (0 == death_clock(philo, philo->status))
			return ;
		philo->status = philo->status->next;
	}
	i = 0;
	while (i < philo->their_number)
		pthread_join(th[i++], NULL);
	mutex_destroyer(philo);
	free(th);
	printf("\033[0;31mSimulation stopped\n\033[0m");
}
