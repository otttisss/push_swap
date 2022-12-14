/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qick_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:48:34 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:48:36 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_four(t_pslist **a, t_pslist **b, int len)
{
	if (len == 4)
	{
		pa_pb(a, b, 2);
		if ((*a)->value > (*a)->next->value)
			sa_sb(a, 1);
		pa_pb(a, b, 2);
		if ((*b)->value < (*b)->next->value)
			ra_rb(b, 2);
		if ((*a)->value > (*a)->next->value)
			ra_rb(a, 1);
		if ((*b)->value > (*a)->next->value)
			pa_pb(a, b, 1);
		if (find_max(*a) == (*a)->value)
			ra_rb(a, 1);
		if ((*a)->value > (*a)->next->value)
			sa_sb(a, 1);
		pa_pb(a, b, 1);
		if ((*a)->value > (*a)->next->value)
			sa_sb(a, 1);
		pa_pb(b, a, 2);
		if ((*a)->value > (*a)->next->value)
			sa_sb(a, 1);
	}
}

static void	sort_three(t_pslist **s)
{
	if ((*s)->value < (*s)->next->value \
			&& (*s)->next->value < (*s)->next->next->value)
		return ;
	if ((*s)->value < (*s)->next->value \
			&& (*s)->next->next->value > (*s)->value)
	{
		rra_rrb(s, 1);
		sa_sb(s, 1);
	}
	else if ((*s)->value < (*s)->next->value \
			&& (*s)->next->next->value < (*s)->value)
		rra_rrb(s, 1);
	if ((*s)->value > (*s)->next->value && (*s)->next->next->value \
		> (*s)->next->value && (*s)->next->next->value > (*s)->value)
		sa_sb(s, 1);
	else if ((*s)->value > (*s)->next->next->value && \
	(*s)->next->next->value > (*s)->next->value)
		ra_rb(s, 1);
	if ((*s)->value > (*s)->next->value && \
			(*s)->next->value > (*s)->next->next->value)
	{
		ra_rb(s, 1);
		sa_sb(s, 1);
	}
}

static void	sort_five(t_pslist **a, t_pslist **b)
{
	while (stack_len(*a) > 3)
	{
		while (find_elem(0, *a) == 5 || find_elem(1, *a) == 5)
			rra_rrb(a, 1);
		while ((*a)->index > 1)
			ra_rb(a, 1);
		pa_pb(a, b, 2);
	}
	if ((*b)->value < (*b)->next->value)
		sa_sb(b, 2);
	sort_three(a);
	pa_pb(a, b, 1);
	pa_pb(a, b, 1);
}

void	short_sort(t_pslist **a, t_pslist **b, int len)
{
	if (len == 1)
		return ;
	if (len == 2 && (*a)->value > (*a)->next->value)
		ft_printf("sa\n");
	if (len == 3)
		sort_three(a);
	if (len == 4)
		sort_four(a, b, len);
	if (len == 5)
		sort_five(a, b);
}
