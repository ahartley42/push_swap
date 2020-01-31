/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:39:36 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/26 14:00:28 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	normal(t_psl *stack)
{
	t_psl	*cmp;
	t_psl	*it;

	it = stack;
	while (it)
	{
		it->n++;
		cmp = stack;
		while (cmp)
		{
			if (it->a > cmp->a)
				it->n++;
			cmp = cmp->next;
		}
		it = it->next;
	}
	ordered(stack, NULL);
}
