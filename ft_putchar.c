/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:52:50 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 17:42:21 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c, int *counter, int *check_write)
{
	if (write(1, &c, 1) == -1)
	{
		*check_write = -1;
		return ;
	}
	*counter = *counter + 1;
}
