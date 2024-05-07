/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:06:17 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_formatted(const char *format,
								va_list args, int *counter, int *check_write)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), counter, check_write);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), counter, check_write);
	else if (*format == 'p')
	{
		ft_putstr("0x", counter, check_write);
		ft_putptr(va_arg(args, void *), counter, check_write);
	}
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), counter, check_write);
	else if (*format == 'u')
		ft_putunsnbr(va_arg(args, unsigned int), counter, check_write);
	else if (*format == 'x' || *format == 'X')
		ft_puthex(va_arg(args, unsigned int), counter, *format, check_write);
	else if (*format == '%')
		ft_putchar('%', counter, check_write);
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
			ft_putchar(format[i], counter, check_write);
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
