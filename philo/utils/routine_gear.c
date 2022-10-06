/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_gear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:02:12 by aabeid            #+#    #+#             */
/*   Updated: 2022/06/12 14:37:00 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	printer(int clock, int idx, char *msg, t_vars *mute)
{
	pthread_mutex_lock(&mute->print);
	printf("%d %d %s\n", clock, idx, msg);
	if (msg[0] != 'd')
		pthread_mutex_unlock(&mute->print);
}

void	sleeping_and_thinking(t_vars *p, t_status *status)
{
	// pthread_mutex_lock(&p->print);
	// printf("%i %i is sleeping...\n", p->clock, status->idx);
	// pthread_mutex_unlock(&p->print);
	printer(p->clock, status->idx, "is sleeping...", p);
	ft_usleep(p->time_to_sleep);
	p->clock = get_time() - p->start_time;
	printer(p->clock, status->idx, "is thinking...", p);
	// pthread_mutex_lock(&p->print);
	// printf("%i %i is thinking...\n", p->clock, status->idx);
	// pthread_mutex_unlock(&p->print);
}

void	eating(t_vars *p, t_status *status)
{	
	forks_on(p, status, 1);
	if (status->rf == 1 && status->lf == 1)
	{
		status->is_eating = 1;
		// pthread_mutex_lock(&p->print);
		// printf("\e[0;30m\e[42m%i %i is eating...\e[0m\e[0m\n", p->clock, status->idx);
		// pthread_mutex_unlock(&p->print);
		printer(p->clock, status->idx, "is eating...", p);
		status->last_meal = p->clock;
		ft_usleep(p->time_to_eat);
		p->clock = get_time() - p->start_time;
		status->is_eating = 0;
		forks_on(p, status, 0);
	}
}
