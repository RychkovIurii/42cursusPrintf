/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:46:27 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:05:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex(unsigned int n, int *counter, char format, int *check_write)
{
	char	c;

	c = '\0';
	if (*check_write == -1)
		return ;
	if (n >= 16)
	{
		ft_puthex(n / 16, counter, format, check_write);
		if (*check_write == -1)
			return ;
		ft_puthex(n % 16, counter, format, check_write);
	}
	else
	{
		if (n < 10)
			c = n + '0';
		else if (format == 'X')
			c = n - 10 + 'A';
		else if (format == 'x')
			c = n - 10 + 'a';
		ft_putchar(c, counter, check_write);
	}
}
