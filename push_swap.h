/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:37:18 by ahartley          #+#    #+#             */
/*   Updated: 2019/08/22 09:13:37 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_psl
{
	int				a;
	struct s_psl	*next;
}					t_psl;

void	in_cmd(char *cmd, t_psl **s1, t_psl **s2);
void	sort_3(t_psl *s, t_psl *s2);
void	sort_5(t_psl *s, t_psl *s2);
int		ordered(t_psl *head, t_psl *empty);

#endif
