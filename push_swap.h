/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahartley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:37:18 by ahartley          #+#    #+#             */
/*   Updated: 2019/11/05 19:57:06 by ahartley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>

typedef struct		s_psl
{
	int				a;
	int				n;
	struct s_psl	*next;
}					t_psl;

void				err(void);
void				error_check(int ac, char **av);
void				numeral(char **s);
void				in_cmd(char *cmd, t_psl **s1, t_psl **s2);
void				sort_3(t_psl *s, t_psl *s2);
void				sort_5(t_psl *s, t_psl *s2);
int					ordered(t_psl *head, t_psl *empty);
t_psl				*new_link(int content);
void				normal(t_psl *stack);
int					find_min(t_psl *s);
int					find_max(t_psl *s);
void				pushback_b(int min, int max, t_psl **s1, t_psl **s2);
void				ps_algo_auto(int min, int max, t_psl **s1, t_psl **s2);
void				printstack(t_psl *sa, t_psl *sb);
void				rot_top(int min, t_psl **s1, t_psl **s2);
int					count_iter(t_psl *stack);
int					find_val(int val, t_psl *stack);
void				rota_tune(int min, t_psl **sa, t_psl **sb);
void				rotb_tune(t_psl **sa, t_psl **sb);
char				*decide_rot(int min, int max, int rng, t_psl *sa);
void				freedom(t_psl **list, t_psl **list2, t_psl **head);

#endif
