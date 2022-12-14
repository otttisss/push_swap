/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:49:40 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:49:41 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include "ft_printf.h"

typedef struct s_pslist
{
	int					index;
	int					value;
	struct s_pslist		*next;
}	t_pslist;

void		sa_sb(t_pslist **stack, int flag);
void		ss(t_pslist **a, t_pslist **b);
void		pa_pb(t_pslist **a, t_pslist **b, int flag);
void		ra_rb(t_pslist **stack, int flag);
void		rr(t_pslist **a, t_pslist **b);
void		rra_rrb(t_pslist **stack, int flag);
void		rrr(t_pslist **a, t_pslist **b);
void		full_sort_end(t_pslist **a, t_pslist **b);
void		full_sort_begin(t_pslist **a, t_pslist **b);
void		short_sort(t_pslist **a, t_pslist **b, int len);
int			pivot(t_pslist **stack);
int			position_find(t_pslist *current);
int			max_index_find(t_pslist *current);
int			find_elem(int index, t_pslist *stack);
int			find_max(t_pslist *stack);
int			stack_len(t_pslist *stack);
void		free_stack(t_pslist **stack);
void		double_checker(t_pslist *first);
int			check_inp(char *inp);
int			is_sorted(t_pslist *a);
void		index_stack(t_pslist *stack, const int *arr);
int			*create_array(t_pslist *stack, int len);
t_pslist	*add_new_cell(void);
void		terminate(void);
#endif
