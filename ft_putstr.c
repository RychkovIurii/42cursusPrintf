/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:52:05 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 16:01:02 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *s, int *counter)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*counter = *counter + 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], counter);
		i++;
	}
}
