/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:12:44 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/28 18:12:48 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printdec(int n)
{
	int	length;

	ft_putnbr_fd(n, 1);
	length = 0;
	if (n < 0)
		length++;
	length += numlength(n);
	return (length);
}

int	printundec(unsigned int n)
{
	int	length;

	length = numlength(n);
	if (n > 9)
	{
		printundec(n / 10);
		n %= 10;
	}
	if (n <= 9)
		ft_putchar_fd(n + 48, 1);
	return (length);
}

int	printhex(unsigned long n, char type)
{
	char			*hex;
	int				length;
	unsigned int	aux;
	int				i;

	length = numlength(n);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (length);
	}
	hex = malloc(sizeof(char) * (length + 1));
	i = 0;
	while (n != 0)
	{
		aux = n % 16;
		if (aux <= 9)
			hex[i++] = aux + 48;
		else if (aux > 9 && type == 'X')
			hex[i++] = aux + 55;
		else if (aux > 9 && type == 'x')
			hex[i++] = aux + 87;
		n /= 16;
	}
	hex[i] = '\0';
	i--;
	while (i >= 0)
		ft_putchar_fd(hex[i--], 1);
	free(hex);
	return (length);
}

int	numlength(long long int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}
