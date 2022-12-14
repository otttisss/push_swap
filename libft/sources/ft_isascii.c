/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:15:55 by ldione            #+#    #+#             */
/*   Updated: 2021/10/12 16:29:31 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int l)
{
	if (l >= 0 && l <= 127)
		return (1);
	else
		return (0);
}
