/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:06:22 by ahartley          #+#    #+#             */
/*   Updated: 2019/09/11 10:29:02 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

/*void printstack(t_psl *s)
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
}*/

static void	err(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

static void error_check(int ac, char **av)
{
	int		i;
	int		j;
	char	*s = NULL;

	i = 0;
	if (ac < 2)
		err();
	while (av[i])
	{
		s = ft_itoa(ft_atoi(av[i]));
		if (!ft_strequ(s, av[i]))
			err();
		i++;
		free(s);
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

int		ordered(t_psl *head, t_psl *empty)
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

int			main(int ac, char **av)
{
	t_psl	*store;
	t_psl	*store2;
	t_psl	*go;
	int		i;
	char	buf[6];

	av++;
	i = 0;
	if (ac == 2)
	{
		av = ft_strsplit(av[0], ' ');
		while (av[++i])
			ac++;
	}
	error_check(ac, &av[0]);
	i = 0;
	ft_bzero(buf, 6);
	store = new_link(ft_atoi(av[i++]));
	store2 = NULL;
	go = store;
	while (i + 1 < ac)
	{
		go->next = new_link(ft_atoi(av[i]));
		go = go->next;
		i++;
	}
	normal(store);
//	printstack(store); 					//creation bug check
	ordered(store, store2);
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
//		printstack(store); 				//print stack A
//		printstack(store2); 			//print stack B
		ordered(store, store2);
		ft_bzero(buf, 4);
	}
	write(1, "KO\n", 3);
	return (0);
}
