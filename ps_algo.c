/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:38:49 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/26 14:03:50 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int		find_min(t_psl *s)
{
	int	ans;

	ans = s->n;
	while (s->next)
	{
		s = s->next;
		if (s->n < ans)
			ans = s->n;
	}
	return (ans);
}

int		find_max(t_psl *s)
{
	int	ans;

	ans = s->n;
	while (s->next)
	{
		s = s->next;
		if (s->n > ans)
			ans = s->n;
	}
	return (ans);
}

void	sort_3(t_psl *s, t_psl *s2)
{
	if (s->n == find_max(s))
		in_cmd("ra", &s, &s2);
	if (s->next->n == find_max(s) && s->next->next)
		in_cmd("rra", &s, &s2);
	if (s->next->n == find_min(s))
		in_cmd("sa", &s, &s2);
}

void	sort_5(t_psl *s, t_psl *s2)
{
	int	min;
	int	max;
	int	c;

	min = find_min(s);
	max = find_max(s);
	c = 0;
	while (c < max - 3)
	{
		if (s->n == min || s->n == max)
		{
			in_cmd("pb", &s, &s2);
			c++;
		}
		else if (s->next->n == min || s->next->n == max || \
				((s->next->next->n == min || s->next->next->n == max) && !s2))
			in_cmd("ra", &s, &s2);
		else
			in_cmd("rra", &s, &s2);
	}
	sort_3(s, s2);
	while (s2)
		in_cmd("pa", &s, &s2);
	if (s->n < s->next->n && c > 1)
		in_cmd("sa", &s, &s2);
	if (s->n > s->next->n)
		in_cmd("ra", &s, &s2);
}
