/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:48:16 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:52:30 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_pslist	*init_structure(int count, char **arg)
{
	t_pslist	*first;
	t_pslist	*tmp;
	int			i;

	i = 1;
	first = add_new_cell();
	tmp = first;
	while (i < count)
	{
		if (check_inp(arg[i]))
		{
			free_stack(&first);
			terminate();
		}
		tmp->value = ft_atoi(arg[i]);
		if (i < count - 1)
		{
			tmp->next = add_new_cell();
			tmp = tmp->next;
		}
		i++;
	}
	(double_checker(first));
	return (first);
}

static void	ask_to_sort(t_pslist **a, t_pslist **b, int a_len)
{
	if (is_sorted(*a))
		return ;
	if (a_len < 6)
	{
		short_sort(a, b, a_len);
		free_stack(a);
		return ;
	}
	else
	{
		full_sort_begin(a, b);
		full_sort_end(a, b);
	}
}

int	main(int argc, char **argv)
{
	int			s_len;
	t_pslist	*a;
	t_pslist	*b;

	if (argc < 2)
		return (0);
	a = init_structure(argc, argv);
	if (!a)
		terminate();
	b = NULL;
	s_len = stack_len(a);
	ask_to_sort(&a, &b, s_len);
	free_stack(&a);
	return (0);
}
