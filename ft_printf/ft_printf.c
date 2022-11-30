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

static int	printchr(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	printstr(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (0);
	}
	else
		ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	printpointer(unsigned long long ptr)
{
	int	length;

	ft_putstr_fd("0x7ff", 1);
	length = printhex(ptr, 'x');
	return (length);
}

static int	checktype(va_list args, char type)
{
	int	length;

	length = 0;
	if (type == 'c')
		length += printchr(va_arg(args, int));
	else if (type == 's')
		length += printstr(va_arg(args, char *));
	else if (type == 'p')
		length += printpointer(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		length += printdec(va_arg(args, int));
	else if (type == 'u')
		length += printundec(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		length += printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		length += printchr('%');
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += checktype(args, str[i + 1]);
			i += 2;
			continue ;
		}
		ft_putchar_fd(str[i], 1);
		length++;
		i++;
	}
	return (length);
}


int	main(void)
{
	int				n;
	char			c;
	char			*str;
	unsigned int	un;

	n = -10;
	un = 9;
	str = "Hello";
	c = 'L';
	printf("char: %c\n", c);
	ft_printf("my char: %c\n", c);
	printf("string: %s\n", str);
	ft_printf("my string: %s\n", str);
	printf("pointer: %p\n", (void *)&n);
	ft_printf("my pointer: %p\n", (void *)&n);
	printf("decimal: %d\n", n);
	ft_printf("my decimal: %d\n", n);
	printf("int: %i\n", n);
	ft_printf("my int: %i\n", n);
	printf("unsigned: %u\n", un);
	ft_printf("my unsigned: %u\n", un);
	printf("hex low: %x\n", 590);
	ft_printf("my hex low: %x\n", 590);
	printf("hex up: %X\n", 590);
	ft_printf("my hex up: %X\n", 590);
	printf("percent: %%\n");
	ft_printf("my percent: %%\n");
}
