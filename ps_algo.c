/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:38:49 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/30 12:01:54 by ahartley         ###   ########.fr       */
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
	int	c;

	c = 0;
	while (c < 2)
	{
		if (s->n == 1 || s->n == 5)
		{
			in_cmd("pb", &s, &s2);
			c++;
		}
		else if (s->next->n == 1 || s->next->n == 5 || \
				((s->next->next->n == 1 || s->next->next->n == 5) && !s2))
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
