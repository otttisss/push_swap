/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:47:42 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:47:47 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_find(t_pslist *current)
{
	int	len;
	int	check;
	int	pos;

	pos = 1;
	if (!current)
		return (0);
	len = stack_len(current);
	check = max_index_find(current);
	while (current->next && current->index != check)
	{
		pos++;
		current = current->next;
	}
	if (pos > len / 2)
		check = 1;
	else
		check = 0;
	return (check);
}

int	find_elem(int index, t_pslist *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	find_max(t_pslist *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	max_index_find(t_pslist *current)
{
	int	max_index;

	max_index = 1;
	if (current)
	{
		max_index = current->index;
		while (current != NULL)
		{
			if (max_index < current->index)
				max_index = current->index;
			current = current->next;
		}
	}
	return (max_index);
}
