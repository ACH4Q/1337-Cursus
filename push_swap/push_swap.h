/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaq <machaq@1337.student.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:04:54 by machaq            #+#    #+#             */
/*   Updated: 2025/02/03 15:11:43 by machaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

void    push(t_node **src, t_node **dest, char stack_name); // pb & pa
void    swap(t_node **stack, char stack_name);              // sa & sb
void    rotate(t_node **stack, char stack_name);            // ra & rb
void    reverse_rotate(t_node **stack, char stack_name);    // rra & rrb
void    radix_sort(t_node **stack_a, t_node **stack_b, int size);
void    small_sort(t_node **stack_a, t_node **stack_b, int size);
void    sort_three(t_node **stack);
t_node  *init_stack(int argc, char **argv);
int     is_sorted(t_node *stack);
void    free_stack(t_node **stack);
void    print_stack(t_node *stack); 
int     is_valid_input(char *str);
void    error_exit(void);

#endif
