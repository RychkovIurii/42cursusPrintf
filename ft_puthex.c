/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:46:27 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/06 15:49:45 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex(unsigned int n, int *counter, char format)
{
	char	c;

	if (n >= 16)
	{
		ft_puthex(n / 16, counter, format);
		ft_puthex(n % 16, counter, format);
	}
	else
	{
		if (n < 10)
			c = n + '0';
		else if (format == 'X')
			c = n - 10 + 'A';
		else if (format == 'x')
			c = n - 10 + 'a';
		write(1, &c, 1);
		*counter = *counter + 1;
	}
}
