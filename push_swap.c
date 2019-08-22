/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:34:22 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/22 09:24:22 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

/*static void printstack(t_psl *s)
{
	printf("STACK: ");
	if (!s)
		printf("EMPTY\n");
	else
	{
		while (s->next)
		{
			printf("%d - ", s->a);
			s = s->next;
		}
		printf("%d\n", s->a);
	}
}*/

static void	err(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

static void	error_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2)
		err();
	while (av[i])
	{
		if (!ft_strequ(ft_itoa(ft_atoi(av[i])), av[i]))
			err();
		i++;
	}
	i = 1;
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

t_psl		*new_link(int content)
{
	t_psl	*new;

	if (!(new = (t_psl *)malloc(sizeof(new) + 1)))
		err();
	new->a = content;
	new->next = NULL;
	return (new);
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
		{
			write(1, "OK\n", 3);
			exit(1);
		}
	}
	return (0);
}

/*char	*algo(char *buf, t_psl *s)
{
	t_psl	*tmp;

	tmp = s;

	while (tmp->next->next)
		tmp = tmp->next;
	if (s->next && s->next->next)
	{
		if (s->a < s->next->a && tmp->next->a < s->a)
			buf = ft_strcpy(buf, "rra");
		else if (s->a < s->next->a && s->next->a > s->next->next->a)
			buf = ft_strcpy(buf, "ra");
		else if (s->a > s->next->a)
			buf = ft_strcpy(buf, "sa");
		else
			buf = ft_strcpy(buf, "rra");
	}
	else
		buf = ft_strcpy(buf, "sa");
	return (buf);
}*/

int			main(int ac, char **av)
{
	t_psl	*store;
	t_psl	*store2;
	t_psl	*head;
	int		i;
	char	buf[6];

	error_check(ac, av);
	i = 1;
	ft_bzero(buf, 6);
	store = new_link(ft_atoi(av[i++]));
	store2 = NULL;
	head = store;
	while (i < ac)
	{
		store->next = new_link(ft_atoi(av[i]));
		store = store->next;
		i++;
	}
	store = head;
	ordered(store, store2);
	if (ac == 4)
		sort_3(store, store2);
	if (ac == 6)
		sort_5(store, store2);
	ordered(store, store2);
	//algo(buf, store);
	while (write(1, buf, 5) > 0 && write(1, "\n", 1) > 0)
	{
		i = 0;
		in_cmd(buf, &store, &store2);
//		printstack(store);
//		printstack(store2);
		ordered(store, store2);
		ft_bzero(buf, 4);
		//algo(buf, store);
	}
	write(1, "KO\n", 3);
	return (0);
}
