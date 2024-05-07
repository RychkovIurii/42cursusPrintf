/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:51:01 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:02:01 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n, int *counter, int *check_write)
{
	char	c;

	if (*check_write == -1)
		return ;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", counter, check_write);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-', counter, check_write);
		if (*check_write == -1)
			return ;
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, counter, check_write);
		if (*check_write == -1)
			return ;
	}
	c = n % 10 + '0';
	ft_putchar(c, counter, check_write);
}
