/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:17:31 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/28 18:31:27 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchr(char c)
{
	ft_putchar_fd(c, 1)
	return (1);
}

int	printstr(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	printpointer(unsigned long long ptr)
{
	int	length;

	ft_putstr_fd("0x", 1);
	length = printhex(ptr);
	return (length);
}
