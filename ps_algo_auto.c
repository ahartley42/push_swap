/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_auto.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:30:38 by ahartley          #+#    #+#             */
/*   Updated: 2019/09/05 13:01:35 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void printstack(t_psl *s)
{
	printf("STACK: ");
	if (!s)
		printf("EMPTY\n");
	else
	{
		while (s->next)
		{
			printf("%d(%d) - ", s->a, s->n);
			s = s->next;
		}
		printf("%d(%d)\n", s->a, s->n);
	}
}

void	pushback_b(int min, int max, t_psl *sa, t_psl *sb)
{
	if (sb)
	{
		while (max >= min)
		{
			if (sb->n == max)
			{
				in_cmd("pa", &sa, &sb);
				max--;
			}
			else
				in_cmd("rb", &sa, &sb);
		printstack(sa);
		printstack(sb);
			ordered(sa, sb);
		}
	}
}

void	ps_algo_auto(int min, int max, t_psl *sa, t_psl *sb)
{
	int	rng;

	rng = max - min + 1;
	while (rng > 0)
	{
		if (sa->n >= min && sa->n <= max)
		{
			in_cmd("pb", &sa, &sb);
			rng--;
		}
		else
			in_cmd("ra", &sa, &sb);
		ordered(sa, sb);
		printstack(sa);
		printstack(sb);
	}
	pushback_b(min, max, sa, sb);
}
