/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:50:10 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/06 15:50:33 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunsnbr(unsigned int n, int *counter)
{
	char	c;

	if (n >= 10)
		ft_putunsnbr(n / 10, counter);
	c = n % 10 + '0';
	ft_putchar(c, counter);
}
