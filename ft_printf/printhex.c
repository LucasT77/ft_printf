/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:34:15 by luaraujo          #+#    #+#             */
/*   Updated: 2022/12/01 17:15:27 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hex_aux(unsigned long n, char type)
{
	char			*hex;
	unsigned int	aux;
	int				i;

	i = numlength(n);
	hex = malloc(sizeof(char) * (i + 1));
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
	return (hex);
}

int	printhex(unsigned long n, char type)
{
	char			*hex;
	int				i;

	i = numlength(n);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (i);
	}
	hex = hex_aux(n, type);
	i = ft_strlen(hex);
	while (i >= 0)
		ft_putchar_fd(hex[i--], 1);
	i = ft_strlen(hex);
	free(hex);
	return (i);
}
