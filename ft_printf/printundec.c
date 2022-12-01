/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printundec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:33:56 by luaraujo          #+#    #+#             */
/*   Updated: 2022/12/01 16:57:29 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
