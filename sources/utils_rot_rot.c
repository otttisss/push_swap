/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rot_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:48:59 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:49:01 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_pslist **stack, int flag)
{
	t_pslist	*tmp;
	t_pslist	*prelast;

	if (!stack || !(*stack))
		return ;
	if (!((*stack)->next))
		return ;
	tmp = *stack;
	prelast = *stack;
	while (prelast->next->next)
		prelast = prelast->next;
	*stack = prelast->next;
	prelast->next->next = tmp;
	prelast->next = NULL;
	if (flag == 1)
		ft_printf("rra\n");
	else if (flag == 2)
		ft_printf("rrb\n");
}

void	rrr(t_pslist **a, t_pslist **b)
{
	rra_rrb(a, 0);
	rra_rrb(b, 0);
	ft_printf("rrr\n");
}
