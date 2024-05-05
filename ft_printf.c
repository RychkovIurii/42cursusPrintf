/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/05 14:08:08 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	*counter = *counter + 1;
}

void	ft_putstr(char *s, int *counter)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		*counter = *counter + 1;
	}
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int	counter;
	va_list	args;

	va_start(args, format);
	//validation for format?
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar(va_arg(args, int), &counter);
			else if (format[i] == 's')
				ft_putstr(va_arg(args, char *), &counter);
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
		{
			ft_putchar(format[i], &counter);
		}
		i++;
	}
	va_end(args);
	printf("mine return - %d\n", counter);
	return (0); //temp not true

}

int	main(void)
{
	char	c;
	char	s[20] = "! Welcome";

	c = '!';
	//Test for char
	ft_printf("Hello Iurii%c\n", c);
	printf("original return - %d\n", printf("Hello Iurii%c\n", c));
	//Test for string
	ft_printf("\nHello Iurii%s\n", s);
	printf("original return - %d\n", printf("\nHello Iurii%s\n", s));
}
