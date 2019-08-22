/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:00:49 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/22 09:13:11 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	rot_cmd(char *cmd, t_psl **s)
{
	t_psl	*temp;
	t_psl	*head;

	if (*s && (*s)->next)
	{
		temp = *s;
		head = *s;
		if (ft_strequ(cmd, "ra") == 1 || ft_strequ(cmd, "rb") == 1)
		{
			while ((*s)->next)
				*s = (*s)->next;
			(*s)->next = temp;
			(*s) = temp->next;
			temp->next = NULL;
		}
		else if (ft_strequ(cmd, "rra") == 1 || ft_strequ(cmd, "rrb") == 1)
		{

			while (head->next->next)
				head = head->next;
			temp = head->next;
			head->next = NULL;
			temp->next = (*s);
			*s = temp;
		}
	}
}

static void	swp_cmd(t_psl **s)
{
	int	temp;

	if (*s && (*s)->next)
	{
		temp = (*s)->next->a;
		(*s)->next->a = (*s)->a;
		(*s)->a = temp;
	}
}

static void	dbl_cmd(char *cmd, t_psl **s1, t_psl **s2)
{
	if (ft_strequ(cmd, "rr") == 1)
	{
		rot_cmd("ra", s1);
		rot_cmd("rb", s2);
	}
	if (ft_strequ(cmd, "rrr") == 1)
	{
		rot_cmd("rra", s1);
		rot_cmd("rrb", s2);
	}
	if (ft_strequ(cmd, "ss") == 1)
	{
		swp_cmd(s1);
		swp_cmd(s2);
	}
}

static void	psh_cmd(t_psl **s1, t_psl **s2)
{
	t_psl	*temp;
	if (*s1)
	{
		temp = (*s1)->next;
		if (*s2)
		{
			(*s1)->next = *s2;
			*s2 = *s1;
		}
		else
		{
			(*s1)->next = NULL;
			*s2 = *s1;
		}
		*s1 = temp;
	}
}

void	in_cmd(char *cmd, t_psl **s1, t_psl **s2)
{
	ft_putendl(cmd);
	if (ft_strequ(cmd, "ra") == 1 || ft_strequ(cmd, "rra") == 1)
		rot_cmd(cmd, s1);
	else if (ft_strequ(cmd, "rb") == 1 || ft_strequ(cmd, "rrb") == 1)
		rot_cmd(cmd, s2);
	else if (ft_strequ(cmd, "rr") == 1 || ft_strequ(cmd, "rrr") == 1 || \
			ft_strequ(cmd, "ss") == 1)
		dbl_cmd(cmd, s1, s2);
	else if (ft_strequ(cmd, "sa") == 1)
		swp_cmd(s1);
	else if (ft_strequ(cmd, "sb") == 1)
		swp_cmd(s2);
	else if (ft_strequ(cmd, "pb") == 1)
		psh_cmd(s1, s2);
	else if (ft_strequ(cmd, "pa") == 1)
		psh_cmd(s2, s1);
	else
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
}
