/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 09:49:51 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/26 09:59:50 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
