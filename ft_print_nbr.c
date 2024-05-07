/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:51:01 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:37:12 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int n, int *counter, int *check_write)
{
	char	c;

	if (*check_write == -1)
		return ;
	if (n == -2147483648)
	{
		ft_print_str("-2147483648", counter, check_write);
		return ;
	}
	else if (n < 0)
	{
		ft_print_char('-', counter, check_write);
		if (*check_write == -1)
			return ;
		n = -n;
	}
	if (n >= 10)
	{
		ft_print_nbr(n / 10, counter, check_write);
		if (*check_write == -1)
			return ;
	}
	c = n % 10 + '0';
	ft_print_char(c, counter, check_write);
}
