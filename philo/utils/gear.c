/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gear.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunner <gunner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:30:27 by aabeid            #+#    #+#             */
/*   Updated: 2022/09/27 12:30:20 by gunner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

int	death_clock(t_vars *p, t_status *status)
{
	if (status -> is_eating == 0 && (p->time_to_die / 1000
			<= (get_time() - p->start_time) - status->last_meal))
	{
		p->clock = get_time() - p->start_time;
		// pthread_mutex_lock(&p->print);
		// printf("%i %i died\n", p->clock, status->idx);
		printer(p->clock, status->idx, "died", p);
		usleep(300);
		mutex_destroyer(p);
		return (0);
	}
	return (1);
}

void	ft_usleep(int waiting)
{
	long long	time;

	time = get_time();
	while (get_time() - time < waiting / 1000)
		usleep(600);
}

long long	get_time(void)
{
	long long		l;
	struct timeval	a;

	gettimeofday(&a, NULL);
	l = ((a.tv_sec * 1000) + (a.tv_usec / 1000));
	return (l);
}

int	input_checker(char **args, int args_sum)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (ft_atoi(args[1]) == 0)
		return (0);
	while (i < args_sum)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	mutex_destroyer(t_vars *p)
{
	int	idx;

	idx = p->status->idx;
	pthread_mutex_destroy(&p->status->lfork);
	pthread_mutex_destroy(&p->status->rfork);
	p->status = p->status->next;
	while (p->status->idx != idx)
	{
		pthread_mutex_destroy(&p->status->lfork);
		pthread_mutex_destroy(&p->status->rfork);
		p->status = p->status->next;
	}
}
