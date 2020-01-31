/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_auto.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:30:38 by ahartley          #+#    #+#             */
/*   Updated: 2019/11/05 22:48:57 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rot_top(int min, t_psl **sa, t_psl **sb, int f)
{
	t_psl	*temp;
	int		i;

	i = 0;
	if (*sa)
	{
		temp = (*sa);
		while (min != 1 && temp->n != min - 1 && i <= min - 1)
		{
			temp = temp->next;
			i++;
		}
		while (min != 1 && (*sa)->n != min - 1)
			in_cmd(decide_rot(min - 1, min - 1, 1, *sa), sa, sb, f);
		if (min != 1)
			in_cmd("ra", sa, sb, f);
	}
}

void	pushback_b(int min, t_psl **sa, t_psl **sb, int f)
{
	int	max;

	max = find_max(*sb);
	if (*sb)
	{
		while (max >= min)
		{
			if ((*sb)->n == max)
			{
				in_cmd("pa", sa, sb, f);
				max--;
			}
			else if (ft_strequ(decide_rot(max, max, 1, *sb), "ra"))
				in_cmd("rb", sa, sb, f);
			else
				in_cmd("rrb", sa, sb, f);
		}
		ordered(*sa, *sb);
	}
}

char	*decide_rot(int min, int max, int rng, t_psl *sa)
{
	int		fst;
	int		lst;
	int		iter;
	t_psl	*tmp;

	iter = 0;
	tmp = sa;
	while (tmp)
	{
		if (tmp->n >= min && tmp->n <= max)
		{
			if (rng == max - min + 1)
				fst = iter;
			if (rng == 1)
				lst = iter;
			rng--;
		}
		tmp = tmp->next;
		iter++;
	}
	if (fst < iter - lst + 1)
		return ("ra");
	else
		return ("rra");
}

void	ps_algo_auto(int min, t_psl **sa, t_psl **sb, int f)
{
	int	rng;
	int	max;
	int	temp;

	max = find_max(*sa);
	rng = 37;
	if (min + rng > max)
		rng = max - min + 1;
	max = min + rng - 1;
	temp = rng;
	while (rng > 0)
	{
		if ((*sa)->n >= min && (*sa)->n <= max)
		{
			in_cmd("pb", sa, sb, f);
			rng--;
		}
		else
			in_cmd(decide_rot(min, max, temp, *sa), sa, sb, f);
		ordered(*sa, *sb);
	}
	rot_top(min, sa, sb, f);
	pushback_b(min, sa, sb, f);
}
