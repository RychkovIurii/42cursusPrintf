/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:46:48 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:57:40 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(void *p, int *counter, int *check_write)
{
	char			c;
	unsigned long	ptr;

	ptr = (unsigned long)p;
	if (*check_write == -1)
		return ;
	if (ptr >= 16)
	{
		ft_print_ptr((void *)(ptr / 16), counter, check_write);
		if (*check_write == -1)
			return ;
		ft_print_ptr((void *)(ptr % 16), counter, check_write);
	}
	else
	{
		if (ptr < 10)
			c = ptr + '0';
		else
			c = ptr - 10 + 'a';
		ft_print_char(c, counter, check_write);
		if (*check_write == -1)
			return ;
	}
}
