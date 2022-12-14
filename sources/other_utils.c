/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:48:24 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:48:26 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot(t_pslist **stack)
{
	int	n;

	if (stack_len(*stack) > 300)
		n = 30;
	else
		n = 15;
	return (n);
}

int	*sort_array(int *arr, int len)
{
	int	count;
	int	i;
	int	tmp;

	count = 0;
	while (count < len)
	{
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = tmp;
			}
			i++;
		}
		count++;
	}
	return (arr);
}

void	index_stack(t_pslist *stack, const int *arr)
{
	int			i;
	t_pslist	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		while (tmp->value != arr[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
		i = 0;
	}
}

int	*create_array(t_pslist *stack, int len)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(len * sizeof(int));
	i = 0;
	if (!arr)
		terminate();
	while (i < len)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	sort_array(arr, len);
	return (arr);
}

void	terminate(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
