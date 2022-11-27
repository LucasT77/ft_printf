/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:58:32 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/25 18:04:37 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	checktype(va_list args, char type)
{
	int	length;

	length = 0;
	if (type == 'c')
		length += printchr(va_arg(args, char));
	else if (type == 's')
		length += printstr(va_arg(args, char *));
	else if (type == 'p')
		length += printpointer(va_arg(args, void*));
	else if (type == 'd' || type == 'i')
		length += printdec(va_arg(args, int));
	else if (type == 'u')
		length += printundec(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		length += printhex(va_arg(args, int), type);
	else if (type == '%')
		length += printchr('%');
	return (length);
}

int ft_printf(const char *str, ...)
{
	size_t	i,
	size_t	length;
	
	va_list	args;
	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += checktype(args, str[i + 1])
			i += 2;
			continue ;
		}
		ft_putchar(str[i], 1);
		length++;
		i++;
	}
}
