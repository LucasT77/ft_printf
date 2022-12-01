/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:33:40 by luaraujo          #+#    #+#             */
/*   Updated: 2022/12/01 16:58:06 by luaraujo         ###   ########.fr       */
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
