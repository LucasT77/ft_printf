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

/*
int	main(void)
{
	int				n;
	char			c;
	char			*str;
	unsigned int	un;

	n = -435;
	un = 56707;
	str = "Hello World";
	c = 'L';

	printf("%i\n", printf("char: %c\n", c));
	ft_printf("ft: %i\n", ft_printf("char: %c\n", c));
    
	ft_printf("\n");
	printf("%i\n", printf("string: %s\n", str));
	ft_printf("ft: %i\n", ft_printf("string: %s\n", str));
    
	ft_printf("\n");
	printf("%i\n", printf("pointer: %p\n", (void *)&n));
	ft_printf("ft: %i\n", ft_printf("pointer: %p\n", (void *)&n));
    
	ft_printf("\n");
	printf("%i\n", printf("decimal: %d\n", n));
	ft_printf("ft: %i\n", ft_printf("decimal: %d\n", n));
    
	ft_printf("\n");
	printf("%i\n", printf("int: %i\n", n));
	ft_printf("ft: %i\n", ft_printf("int: %i\n", n));
    
	ft_printf("\n");
	printf("%i\n", printf("unsigned: %u\n", un));
	ft_printf("ft: %i\n", ft_printf("unsigned: %u\n", un));
    
	ft_printf("\n");
	printf("%i\n", printf("hex low: %x\n", un));
	ft_printf("ft: %i\n", ft_printf("hex low: %x\n", un));
    
	ft_printf("\n");
	printf("%i\n", printf("hex up: %X\n", un));
	ft_printf("ft: %i\n", ft_printf("hex up: %X\n", un));
    
	ft_printf("\n");
	printf("%i\n", printf("percent: %%\n"));
	ft_printf("ft: %i\n", ft_printf("percent: %%\n"));
}
*/