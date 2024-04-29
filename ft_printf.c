/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/04/29 22:48:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	args;
	va_start(args, format);

	//validation for format?
	i = 0;
	while (format[i])
	{
		if (format[i] == '%') 
		{
			i++;
			if (format[i] == 'c')
				continue; //temp print &char
			else if (format[i] == 's')
				continue; //temp print string
			else if (format[i] == 'p')
				continue; //temp print pointer
			else if (format[i] == 'd')
				continue; //temp print decimal
			else if (format[i] == 'i')
				continue; //temp print int
			else if (format[i] == 'u')
				continue; //temp print unsigned dec
			else if (format[i] == 'x')
				continue; //temp print hex lowercase
			else if (format[i] == 'X')
				continue; //temp print hex uppercase
			else if (format[i] == '%')
				continue; //temp print %
		}
		else
			continue; //print char
		i++;
	}
	va_end(args);
	return 0; //temp not true

}