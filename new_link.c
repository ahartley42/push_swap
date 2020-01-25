/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 09:49:51 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/29 14:51:18 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_psl	*new_link(int content)
{
	t_psl	*new;

	if (!(new = (t_psl *)malloc(sizeof(new) + 1)))
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	new->a = content;
	new->n = 0;
	new->next = NULL;
	return (new);
}

void	freedom(t_psl **list, t_psl **list2, t_psl **head)
{
	if (*list)
	{
		if ((*list)->next != NULL)
			freedom(&(*list)->next, &(*list2), &(*head));
		free(*list);
		*list = NULL;
	}
	else if (*list2)
	{
		if ((*list2)->next != NULL)
			freedom(&(*list), &(*list2)->next, &(*head));
		free(*list2);
		*list2 = NULL;
	}
	else if (*head)
	{
		if ((*head)->next != NULL)
			freedom(&(*list), &(*list2), &(*head)->next);
		free(*head);
		*head = NULL;
	}
}
