/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:35:48 by luaraujo          #+#    #+#             */
/*   Updated: 2022/12/01 16:58:19 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printpointer(unsigned long long ptr)
{
	int	length;

	ft_putstr_fd("0x", 1);
	length = printhex(ptr, 'x');
	return (length + 2);
}
