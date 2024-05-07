/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:50:10 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:03:06 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunsnbr(unsigned int n, int *counter, int *check_write)
{
	char	c;

	if (*check_write == -1)
		return ;
	if (n >= 10)
	{
		ft_putunsnbr(n / 10, counter, check_write);
		if (*check_write == -1)
			return ;
	}
	c = n % 10 + '0';
	ft_putchar(c, counter, check_write);
}
