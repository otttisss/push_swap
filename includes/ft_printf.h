/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:49:50 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/10 13:49:52 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

unsigned int	ft_hex_putnbr_upp(unsigned int hex, unsigned	int count);
unsigned int	ft_hex_putnbr_low(unsigned long long hex, unsigned int count);
unsigned int	ft_putnbr_uns(unsigned int n, unsigned int count);
int				ft_putptr(uintptr_t ptr);
int				ft_putchar(char c);
unsigned int	ft_putstr(char *s);
unsigned int	ft_putnbr(int n, unsigned int count);
unsigned int	ft_check_opt(va_list params, const char *arg);
int				ft_printf(const char *arg, ...);

#endif
