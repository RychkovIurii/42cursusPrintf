/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:36:53 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_formatted(const char *format,
								va_list args, int *counter, int *check_write)
{
	if (*format == 'c')
		ft_print_char(va_arg(args, int), counter, check_write);
	else if (*format == 's')
		ft_print_str(va_arg(args, char *), counter, check_write);
	else if (*format == 'p')
	{
		ft_print_str("0x", counter, check_write);
		ft_print_ptr(va_arg(args, void *), counter, check_write);
	}
	else if (*format == 'd' || *format == 'i')
		ft_print_nbr(va_arg(args, int), counter, check_write);
	else if (*format == 'u')
		ft_print_unsnbr(va_arg(args, unsigned int), counter, check_write);
	else if (*format == 'x' || *format == 'X')
		ft_print_hex(va_arg(args, unsigned int), counter, *format, check_write);
	else if (*format == '%')
		ft_print_char('%', counter, check_write);
}

static void	ft_helper(const char *format, va_list args,
											int *counter, int *check_write)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			ft_print_formatted(&format[i], args, counter, check_write);
		}
		else
		{
			ft_print_char(format[i], counter, check_write);
		}
		if (*check_write == -1)
			break ;
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	int		check_write;
	va_list	args;

	va_start(args, format);
	counter = 0;
	check_write = 1;
	ft_helper(format, args, &counter, &check_write);
	va_end(args);
	if (check_write == -1)
		return (-1);
	return (counter);
}
