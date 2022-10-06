/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:02:30 by aabeid            #+#    #+#             */
/*   Updated: 2022/03/27 13:25:04 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

t_status	*ft_lstnew(int idx, int must_eat)
{
	t_status	*p;

	p = malloc(sizeof (t_status));
	if (p == NULL)
		return (NULL);
	pthread_mutex_init(&p->lfork, NULL);
	pthread_mutex_init(&p->rfork, NULL);
	p -> lf = 0;
	p -> rf = 0;
	p -> idx = idx;
	p -> is_eating = 0;
	p -> must_eat = must_eat;
	p -> prev = NULL;
	p -> next = NULL;
	return (p);
}
