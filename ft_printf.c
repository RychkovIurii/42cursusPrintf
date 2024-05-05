/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/05 15:10:05 by irychkov         ###   ########.fr       */
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

void	ft_putnbr(int n, int *counter)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*counter = *counter + 11;
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		*counter = *counter + 1;
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, counter);
	c = n % 10 + '0';
	*counter = *counter + 1;
	write(1, &c, 1);
}

void	ft_putunsnbr(unsigned int n, int *counter)
{
	char	c;

	if (n >= 10)
		ft_putunsnbr(n / 10, counter);
	c = n % 10 + '0';
	*counter = *counter + 1;
	write(1, &c, 1);
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
				ft_putnbr(va_arg(args, int), &counter);
			else if (format[i] == 'i')
				ft_putnbr(va_arg(args, int), &counter);
			else if (format[i] == 'u')
				ft_putunsnbr(va_arg(args, unsigned int), &counter);
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
	char			c;
	int				number;
	int				number2;
	unsigned int	number3;
	char	s[20] = "! Welcome";

	c = '!';
	number = -2147483648;
	number2 = 2147483647;
	number3 = 4294967295;

	//Test for %c
	ft_printf("Hello Iurii%c\n", c);
	printf("original return - %d\n", printf("Hello Iurii%c\n", c));

	//Test for %s
	ft_printf("\nHello Iurii%s\n", s);
	printf("original return - %d\n", printf("\nHello Iurii%s\n", s));

	//Test for %d
	ft_printf("\n%d\n", number);
	printf("original return - %d\n", printf("\n%d\n", number));

	//Test for %i
	ft_printf("\n%i\n", number2);
	printf("original return - %d\n", printf("\n%i\n", number2));

	//Test for %u
	ft_printf("\n%u\n", number3);
	printf("original return - %d\n", printf("\n%u\n", number3));
}
