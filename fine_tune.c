/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fine_tune.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 09:42:19 by ahartley          #+#    #+#             */
/*   Updated: 2019/09/16 15:26:32 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int		count_iter(t_psl *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int		find_val(int val, t_psl *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		while (stack->n != val)
		{
			i++;
			stack = stack->next;
		}
	}
	return (i);
}

void	rota_tune(int min, t_psl **sa, t_psl **sb)
{
	t_psl	*thru;
	int		i;
	int		j;

	thru = *sa;
	if (min > 0)
	{
		i = count_iter(thru);
		j = find_val(min);
		while ((*sa)->n != min)
		{
			if (j <= i / 2)
				in_cmd("ra", sa, sb);
			else
				in_cmd("rra", sa, sb);
		}
		in_cmd("ra", sa, sb);
	}
}

void	rotb_tune(t_psl **sa, t_psl **sb)
{
	t_psl	*thru;
	int		i;
	int		j;

	thru = *sb;
	while (*sb)
	{
		i = count_iter(thru);
		j = find_val(thru);
		if (j <= i / 2)
			in_cmd("rb", sa, sb);
		else
			in_cmd("rrb", sa, sb);
	}
}

// concerning ints

int	fx_1(t_psl *s, int min, int max)
{
	int	i;

	i = 0;
	while (s->n < min && s->n > max)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int fx_2(t_psl *s, int min, int max)
{
	int	rng;
	int	i;

	rng = max - min + 1;
	i = count_iter(s);
	while (rng > 0)
	{
		if (s->n >= min && s->n <= max)
			rng--;
		if (rng > 0)
		{
			s = s->next;
			i--;
		}
	}
	return (i);
}
