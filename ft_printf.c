/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 16:30:12 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_formatted(const char *format, va_list args, int *counter)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (*format == 'p')
	{
		write(1, "0x", 2);
		*counter = *counter + 2;
		ft_putptr(va_arg(args, void *), counter);
	}
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (*format == 'u')
		ft_putunsnbr(va_arg(args, unsigned int), counter);
	else if (*format == 'x' || *format == 'X')
		ft_puthex(va_arg(args, unsigned int), counter, *format);
	else if (*format == '%')
		ft_putchar('%', counter);
}

static void	ft_helper(const char *format, va_list args, int *counter)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			ft_print_formatted(&format[i], args, counter);
		}
		else
		{
			write(1, &format[i], 1);
			*counter = *counter + 1;
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	args;

	va_start(args, format);
	counter = 0;
	ft_helper(format, args, &counter);
	va_end(args);
	return (counter);
}
