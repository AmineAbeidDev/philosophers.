/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:05:41 by aabeid            #+#    #+#             */
/*   Updated: 2022/03/27 13:25:28 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

void	ft_lstadd_back(t_status **lst, t_status *new)
{
	t_status	*tail;

	tail = *lst;
	while (tail)
	{
		if (!tail -> next)
		{
			tail -> next = new;
			new -> prev = tail;
			return ;
		}
		tail = tail -> next;
	}
	if (!lst)
		*lst = ft_lstnew(0, 0);
	*lst = new;
}
