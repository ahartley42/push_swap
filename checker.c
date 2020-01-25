/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:06:22 by ahartley          #+#    #+#             */
/*   Updated: 2019/10/29 14:26:56 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	readloop(char *buf, t_psl *store, t_psl *store2)
{
	ft_bzero(buf, 5);
	while (read(0, buf, 3) > 0)
	{
		if (buf[2] == '\n')
			buf[2] = '\0';
		else
		{
			if (read(0, &buf[3], 1) > 0)
			{
				if (buf[3] == '\n')
					buf[3] = '\0';
			}
		}
		in_cmd(buf, &store, &store2);
		ordered(store, store2);
		ft_bzero(buf, 4);
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
			if (ret->n > ret->next->n)
				return (0);
			ret = ret->next;
		}
		if (!ret->next && !empty)
		{
			write(1, "OK\n", 3);
			exit(1);
		}
	}
	return (0);
}

void		maker(int ac, char **av, t_psl **thru)
{
	int	i;

	i = 1;
	while (i < ac - 1)
	{
		(*thru)->next = new_link(ft_atoi(av[i++]));
		*thru = (*thru)->next;
	}
}

int			main(int ac, char **av)
{
	t_psl	*store;
	t_psl	*store2;
	t_psl	*thru;
	int		i;
	char	buf[5];

	av++;
	i = 0;
	if (ac == 2)
	{
		av = ft_strsplit(av[0], ' ');
		while (av[++i])
			ac++;
	}
	i = 0;
	error_check(ac, &av[0]);
	store = new_link(ft_atoi(av[i++]));
	store2 = NULL;
	thru = store;
	maker(ac, av, &thru);
	normal(store);
	ordered(store, store2);
	readloop(buf, store, store2);
	write(1, "KO\n", 3);
	return (0);
}
