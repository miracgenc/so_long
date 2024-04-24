/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migenc <migenc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:29:33 by migenc            #+#    #+#             */
/*   Updated: 2024/04/21 14:29:34 by migenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
# include "stdarg.h"

int		ft_printf(const char *str, ...);

void	ft_putchar(char c, long *i);
void	ft_putstr(char *str, long *i);
void	ft_dectohex(unsigned long p, char c, long *i);
void	ft_putnbr(int n, long *i);
void	ft_putunbr(unsigned int n, long *i);

#endif
