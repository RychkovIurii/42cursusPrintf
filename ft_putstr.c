/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:52:05 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 17:49:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *s, int *counter, int *check_write)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", counter, check_write);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], counter, check_write);
		if (*check_write == -1)
			break ;
		i++;
	}
}
