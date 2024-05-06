/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:46:48 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/06 15:49:12 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putptr(void *p, int *counter)
{
	char			c;
	unsigned long	ptr;

	ptr = (unsigned long)p;
	if (ptr >= 16)
	{
		ft_putptr((void *)(ptr / 16), counter);
		ft_putptr((void *)(ptr % 16), counter);
	}
	else
	{
		if (ptr < 10)
			c = ptr + '0';
		else
			c = ptr - 10 + 'a';
		write(1, &c, 1);
		*counter = *counter + 1;
	}
}
