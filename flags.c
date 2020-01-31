/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:17:23 by ahartley          #+#    #+#             */
/*   Updated: 2020/01/29 13:50:12 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	printstack(t_psl *sa, t_psl *sb)
{
	printf("STACK A: ");
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
	printf("STACK B: ");
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

int		flags(char *str)
{
	int f;
	int i;

	f = 0;
	i = 0;
	if (!str)
		return (0);
	else if (str[i] != '-' && str[i + 1] != '\0')
		return (0);
	while (str[++i])
	{
		if (str[i] == 'v' && (f & 4) == 0)
			f += 4;
		else if (str[i] == 'c' && (f & 2) == 0)
			f += 2;
		else if (str[i] == 'r' && (f & 1) == 0)
			f += 1;
		else
			return (0);
	}
	return (f);
}

void	flag_o(int f, t_psl *sa, t_psl *sb)
{
	if (f & 2)
		printf("\x1b[33m");
	if (f & 4)
		printstack(sa, sb);
	if (f & 2)
		printf("\x1b[0m");
	if (f & 1)
		sleep(1);
}
