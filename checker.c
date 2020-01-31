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

static void	readloop(char *buf, t_psl *store, t_psl *store2, int f)
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
		in_cmd(buf, &store, &store2, f);
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
			write(1, "\x1b[32mOK\x1b[0m\n", 12);
			exit(1);
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_psl	*store;
	t_psl	*store2;
	t_psl	*thru;
	int		flg;
	char	buf[5];

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
	readloop(buf, store, store2, flg);
	write(1, "\x1b[31mKO\x1b[0m\n", 12);
	return (0);
}
