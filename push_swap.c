/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:34:22 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/29 15:30:35 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

static void	err(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

static void	error_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		err();
	while (av[i])
	{
		if (!ft_strequ(ft_itoa(ft_atoi(av[i])), av[i]))
			err();
		i++;
	}
	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strequ(av[i], av[j]))
				err();
			j++;
		}
		i++;
	}
}

int			ordered(t_psl *head, t_psl *empty)
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

int			main(int ac, char **av)
{
	t_psl	*store;
	t_psl	*store2;
	t_psl	*thru;
	int		i;

	av++;
	i = 0;
	if (ac == 2)
	{
		av = ft_strsplit(av[0], ' ');
		while (av[++i])
			ac++;
	}
	error_check(ac, av);
	i = 0;
	store = new_link(ft_atoi(av[i++]));
	store2 = NULL;
	thru = store;
	while (i < ac - 1)
	{
		thru->next = new_link(ft_atoi(av[i++]));
		thru = thru->next;
	}
	ordered(store, store2);
	normal(store);
	if (ac <= 4)
		sort_3(store, store2);
	else if (ac <= 6)
		sort_5(store, store2);
	ordered(store, store2);
	return (0);
}
