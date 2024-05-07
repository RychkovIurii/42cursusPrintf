/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:46:48 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:00:01 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putptr(void *p, int *counter, int *check_write)
{
	char			c;
	unsigned long	ptr;

	ptr = (unsigned long)p;
	if (*check_write == -1)
		return ;
	if (ptr >= 16)
	{
		ft_putptr((void *)(ptr / 16), counter, check_write);
		ft_putptr((void *)(ptr % 16), counter, check_write);
	}
	else
	{
		if (ptr < 10)
			c = ptr + '0';
		else
			c = ptr - 10 + 'a';
		ft_putchar(c, counter, check_write);
		if (*check_write == -1)
			return ;
	}
}
