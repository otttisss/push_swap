/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:46:45 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:47:12 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	if (str[0] == '-' && ft_atoi(str) > 0)
		return (1);
	if (str[0] != '-' && ft_atoi(str) < 0)
		return (1);
	return (0);
}

int	check_inp(char *inp)
{
	int	len;
	int	i;

	i = 0;
	if (inp[i] == '-' && ft_isdigit(inp[i++]))
		i++;
	if (inp[i] == '-' && !ft_isdigit(inp[i++]))
		return (1);
	len = ft_strlen(&inp[i]);
	if (len > 10)
		return (1);
	while (inp[i])
	{
		if (!ft_isdigit(inp[i++]))
			return (1);
	}
	if (len == 10 && check_int(inp))
		return (1);
	return (0);
}

void	double_checker(t_pslist *first)
{
	int	i;
	int	j;
	int	*arr;
	int	s_len;

	s_len = stack_len(first);
	arr = create_array(first, s_len);
	i = 0;
	j = 0;
	while (i < s_len - 1)
	{
		j = i;
		while (j < s_len - 1)
		{
			if (arr[i] == arr[++j])
			{
				free_stack(&first);
				terminate();
			}
		}
		i++;
	}
	index_stack(first, arr);
	free(arr);
}

int	is_sorted(t_pslist *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
		{
			return (0);
			break ;
		}
		a = a->next;
	}
	return (1);
}
