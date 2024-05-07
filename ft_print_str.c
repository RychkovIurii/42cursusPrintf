/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:52:05 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:37:03 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *s, int *counter, int *check_write)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_print_str("(null)", counter, check_write);
		return ;
	}
	while (s[i])
	{
		ft_print_char(s[i], counter, check_write);
		if (*check_write == -1)
			break ;
		i++;
	}
}
