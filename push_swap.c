/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:34:22 by ahartley          #+#    #+#             */
/*   Updated: 2019/11/05 23:11:59 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int		ordered(t_psl *head, t_psl *empty)
{
	t_psl	*ret;

	if (head)
	{
		ret = head;
		while (ret->next)
		{
			if (ret->a > ret->next->a)
				return (0);
			ret = ret->next;
		}
		if (!ret->next && !empty)
			exit(1);
	}
	return (0);
}

void	auto_sort(int ac, t_psl *store, t_psl *store2, int f)
{
	int	i;
	int	range;

	range = 37;
	if (ac <= 4)
		sort_3(&store, &store2, f);
	else if (ac <= 6)
		sort_5(&store, &store2, f);
	else
	{
		i = 1;
		while (i <= ac - 1)
		{
			ps_algo_auto(i, &store, &store2, f);
			i += range;
			ordered(store, store2);
		}
		while (store->n != 1)
			in_cmd("ra", &store, &store2, f);
		ordered(store, store2);
	}
}

int		main(int ac, char **av)
{
	t_psl	*store;
	t_psl	*store2;
	t_psl	*thru;
	int		flg;

	av++;
	if ((flg = flags(*av)) > 0)
	{
		av++;
		ac--;
	}
	ac = av_split(ac, &av);
	error_check(ac, av);
	store = new_link(ft_atoi(av[0]));
	store2 = NULL;
	thru = store;
	maker(ac, av, &thru);
	normal(store);
	auto_sort(ac, store, store2, flg);
	return (0);
}
