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
	write(2, "\x1b[31mError\x1b[0m\n", 15);
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

int		av_split(int ac, char ***av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		*av = ft_strsplit((*av)[0], ' ');
		while ((*av)[++i])
			ac++;
	}
	return (ac);
}
