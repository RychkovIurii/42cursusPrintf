/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:52:50 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:37:19 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, int *counter, int *check_write)
{
	if (write(1, &c, 1) == -1)
	{
		*check_write = -1;
		return ;
	}
	*counter = *counter + 1;
}
