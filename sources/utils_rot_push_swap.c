/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rot_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:48:52 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:48:53 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_pslist **stack, int flag)
{
	t_pslist	*tmp;

	if (!stack || !(*stack))
		return ;
	if (!((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (flag == 1)
		ft_printf("sa\n");
	else if (flag == 2)
		ft_printf("sb\n");
}

void	ss(t_pslist **a, t_pslist **b)
{
	sa_sb(a, 0);
	sa_sb(b, 0);
	ft_printf("ss\n");
}

void	pa_pb(t_pslist **a, t_pslist **b, int flag)
{
	t_pslist	*tmp;

	if (flag == 2)
	{
		if (!a || !(*a))
			return ;
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = (*b);
		(*b) = tmp;
		ft_printf("pb\n");
	}
	else
	{
		if (!b || !(*b))
			return ;
		tmp = (*b);
		(*b) = (*b)->next;
		tmp->next = (*a);
		(*a) = tmp;
		ft_printf("pa\n");
	}
}

void	ra_rb(t_pslist **stack, int flag)
{
	t_pslist	*tmp;
	t_pslist	*last;

	if (!stack || !(*stack))
		return ;
	if (!((*stack)->next))
		return ;
	tmp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
	else if (flag == 2)
		ft_printf("rb\n");
}

void	rr(t_pslist **a, t_pslist **b)
{
	ra_rb(a, 0);
	ra_rb(b, 0);
	ft_printf("rr\n");
}
