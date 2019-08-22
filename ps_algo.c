/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:38:49 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/22 09:33:54 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int		find_min(t_psl *s)
{
	int	ans;

	ans = s->a;
	while (s->next)
	{
		s = s->next;
		if (s->a < ans)
			ans = s->a;
	}
	return (ans);
}

int		find_max(t_psl *s)
{
	int	ans;

	ans = s->a;
	while (s->next)
	{
		s = s->next;
		if (s->a > ans)
			ans = s->a;
	}
	return (ans);
}

void	sort_3(t_psl *s, t_psl *s2)
{
	if (s->a == find_max(s))
		in_cmd("ra", &s, &s2);
	if (s->next->a == find_max(s))
		in_cmd("rra", &s, &s2);
	if (s->next->a == find_min(s))
		in_cmd("sa", &s, &s2);
}

void	sort_5(t_psl *s, t_psl *s2)
{
	int	min;
	int	max;
	int	c;

	c = 0;
	min = find_min(s);
	max = find_max(s);
	while (c < 2)
	{
		if (s->a == min || s->a == max)
		{
			in_cmd("pb", &s, &s2);
			c++;
		}
		else if (s->next->a == min || s->next->a == max || \
				((s->next->next->a == min || s->next->next->a == max) && !s2))
			in_cmd("ra", &s, &s2);
		else
			in_cmd("rra", &s, &s2);
	}
	sort_3(s, s2);
	while (s2)
		in_cmd("pa", &s, &s2);
	if (s->a < s->next->a)
		in_cmd("sa", &s, &s2);
	in_cmd("ra", &s, &s2);
}
