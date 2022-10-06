/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:58:31 by aabeid            #+#    #+#             */
/*   Updated: 2022/03/21 15:50:52 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../linker.h"

int	ft_lstsize(t_status *lst)
{
	int			i;
	t_status	*count;

	i = 0;
	count = lst;
	while (count != 0)
	{
		i++;
		count = count -> next;
	}
	return (i);
}
