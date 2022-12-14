/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:48:43 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:48:44 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_pslist *stack)
{
	int	count;

	count = 1;
	while (stack->next)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_pslist	*add_new_cell(void)
{
	t_pslist	*cell;

	cell = (t_pslist *)malloc(sizeof(t_pslist));
	if (!cell)
		terminate();
	cell->value = 0;
	cell->next = NULL;
	return (cell);
}

void	free_stack(t_pslist **stack)
{
	t_pslist	*copy_stack;
	t_pslist	*buff;

	copy_stack = *stack;
	while (copy_stack)
	{
		buff = copy_stack;
		copy_stack = copy_stack->next;
		free (buff);
	}
	*stack = NULL;
}
