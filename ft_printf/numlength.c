/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlength.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:34:39 by luaraujo          #+#    #+#             */
/*   Updated: 2022/12/02 15:09:59 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numlength(long long int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

int	numlength_unsigned(unsigned long long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}
