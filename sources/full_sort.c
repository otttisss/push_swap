/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:47:57 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:48:01 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	full_sort_end(t_pslist **a, t_pslist **b)
{
	int	check;

	while ((*b) != NULL)
	{
		check = max_index_find(*b);
		if ((*b)->index != check && !position_find(*b))
		{
			while ((*b)->index != check)
				ra_rb(b, 2);
			pa_pb(a, b, 1);
		}
		else if ((*b)->index != check && position_find(*b))
		{
			while ((*b)->index != check)
				rra_rrb(b, 2);
			pa_pb(a, b, 1);
		}
		else if ((*b)->index == check)
			pa_pb(a, b, 1);
	}
}

void	full_sort_begin(t_pslist **a, t_pslist **b)
{
	int		i;
	double	size;
	int		n;

	i = 0;
	n = pivot(a);
	size = stack_len(*a);
	while ((*a) != NULL)
	{
		if (i > 1 && (*a)->index <= i)
		{
			pa_pb(a, b, 2);
			ra_rb(b, 2);
			i++;
		}
		else if ((*a)->index <= i + n)
		{
			pa_pb(a, b, 2);
			i++;
		}
		else if ((*a)->index >= i)
			ra_rb(a, 1);
	}
}
