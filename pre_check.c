/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 07:02:28 by ahartley          #+#    #+#             */
/*   Updated: 2020/01/25 07:02:34 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	err(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

void	numeral(char **s)
{
	int		i;
	char	*test;

	i = 0;
	while (s[i])
	{
		test = ft_itoa(ft_atoi(s[i]));
		if (!ft_strequ(test, s[i]))
		{
			ft_strdel(&test);
			err();
		}
		ft_strdel(&test);
		i++;
	}
}

void	error_check(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	if (ac < 2)
		err();
	numeral(av);
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

void	printstack(t_psl *sa, t_psl *sb)
{
	printf("STACK: ");
	if (!sa)
		printf("EMPTY\n");
	else
	{
		while (sa->next)
		{
			printf("%d(%d) - ", sa->a, sa->n);
			sa = sa->next;
		}
		printf("%d(%d)\n", sa->a, sa->n);
	}
	printf("STACK: ");
	if (!sb)
		printf("EMPTY\n");
	else
	{
		while (sb->next)
		{
			printf("%d(%d) - ", sb->a, sb->n);
			sb = sb->next;
		}
		printf("%d(%d)\n", sb->a, sb->n);
	}
}
