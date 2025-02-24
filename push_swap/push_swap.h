/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:29:06 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/05 13:28:00 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// lst
typedef struct t_list
{
	int				content;
	struct t_list	*next;
	struct t_list	*target;
	int				rank;
	int				index;
	int				med;
	int				cost;
	int				cost_total;
}					t_list;
// lst

// atoi and checkers
int					ft_isdigit(int c);
int					ft_pos_nig(int c);
int					ft_iswspace(int c);
int					dup_checker(int *arr, int len_arr);
int					ft_atoi_checker(char *c, int *string_n);
long				ft_atoi(const char *nptr);
// atoi and checker

// ft_split
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				cal_seg(const char *inp, char cdel);
char				*eseg(const char *start, size_t len);
char				**spseg(const char *inp, char del, char **res);
char				**ft_split(const char *s, char c);
int					spt_to_arr(char ***str, int ac, int str_num);
// ft_split

// instra_base
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
// instra_base

// give_things
void				give_index(t_list **stack);
void				give_rank(t_list **stack_a);
void				complete_it(t_list *temp1, t_list *temp2, int flag);
void				give_target(t_list **stack_a, t_list **stack_b);
// give_things

// instrunctions
void				sa_sb(t_list **stack, char c);
void				ss(t_list **stack_a, t_list **stack_b, char c);
void				ra_rb(t_list **stack, char c);
void				rr(t_list **stack_a, t_list **stack_b, char c);
void				rra_rrb(t_list **stack, char c);
void				rrr(t_list **stack_a, t_list **stack_b, char c);
void				pa_pb(t_list **stack_out, t_list **stack_in, char c);
// instrunctions

// memory_mgmnt
void				ft_free_sp(char ***str, int ac);
void				free_stack(t_list **str);
// memory_mgmnt
// sort
int					put_on_sa(int *arr, int len_arr);
void				sort(t_list **stack_a, t_list **stack_b);
void				sort_five(t_list **sa, t_list **stack_b);
void				move_to_top(t_list **stack, t_list *node, char c);
int					is_sorted(t_list **stack);
void				sort_three(t_list **stack_a);
void				sa_to_sb(t_list **stack_a, t_list **stack_b);
void				give_med(t_list **stack);
void				sb_to_sa(t_list **stack_a, t_list **stack_b, t_list *cheap);
void				put_on_h(t_list **stack_a);
void				sort_more(t_list **stack_a, t_list **stack_b);
// sort

// cost_mgmt
void				cheapst_cost(t_list **stack_a, t_list **stack_b);
void				cal_cost(t_list *node, int size_a, int size_b);
void				give_cost_total(t_list **stack_b);
void				give_cost(t_list **stack);
// cost_mgmt

// ut_bonus

int					do_instra(int *arr, int len_arr);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					do_swap(t_list **stack_a, t_list **stack_b, char *line);
int					spt_to_arr_bonus(char ***str, int ac, int str_num);
#endif