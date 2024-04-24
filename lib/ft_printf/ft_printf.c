/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migenc <migenc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:29:30 by migenc            #+#    #+#             */
/*   Updated: 2024/04/21 14:29:31 by migenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type(char c, va_list *arg, long *i)
{
	if (c == 'c')
		ft_putchar(va_arg(*arg, int), i);
	else if (c == 's')
		ft_putstr(va_arg(*arg, char *), i);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*arg, int), i);
	else if (c == 'p')
	{
		ft_putstr("0x", i);
		ft_dectohex(va_arg(*arg, unsigned long), c, i);
	}
	else if (c == 'u')
		ft_putunbr(va_arg(*arg, unsigned int), i);
	else if (c == 'x' || c == 'X')
		ft_dectohex(va_arg(*arg, unsigned int), c, i);
	else
		ft_putchar(c, i);
}

int	ft_printf(const char *str, ...)
{
	long	i;
	va_list	arg;

	i = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			type(*(++str), &arg, &i);
			str++;
		}
		else
		{
			ft_putchar(*str, &i);
			str++;
		}
	}
	va_end(arg);
	return (i);
}
