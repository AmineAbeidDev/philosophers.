/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:07:03 by aabeid            #+#    #+#             */
/*   Updated: 2022/03/21 15:51:23 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

t_status	*ft_lstlast(t_status *lst)
{
	t_status	*current;

	if (lst == 0)
		return (0);
	current = lst;
	while (current -> next != 0)
		current = current -> next;
	return (current);
}
