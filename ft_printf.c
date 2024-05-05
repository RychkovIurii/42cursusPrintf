/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/05 18:24:05 by irychkov         ###   ########.fr       */
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
		ft_putchar(s[i], counter);
		i++;
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
		ft_putchar('-', counter);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, counter);
	c = n % 10 + '0';
	ft_putchar(c, counter);
}

void	ft_putunsnbr(unsigned int n, int *counter)
{
	char	c;

	if (n >= 10)
		ft_putunsnbr(n / 10, counter);
	c = n % 10 + '0';
	ft_putchar(c, counter);
}

void	ft_puthex(unsigned int n, int *counter, char format)
{
	char	c;

	if (n >= 16)
	{
		ft_puthex(n / 16, counter, format);
		ft_puthex(n % 16, counter, format);
	}
	else
	{
		if (n < 10)
			c = n + '0';
		else if (format == 'X')
			c = n - 10 + 'A';
		else if (format == 'x')
			c = n - 10 + 'a';
		write(1, &c, 1);
		*counter = *counter + 1;
	}
}

void	ft_putptr(void *p, int *counter)
{
	char			c;
	unsigned long	ptr;

	ptr = (unsigned long)p;
	if (ptr >= 16)
	{
		ft_putptr((void *)(ptr / 16), counter);
		ft_putptr((void *)(ptr % 16), counter);
	}
	else 
	{
		if (ptr < 10)
			c = ptr + '0';
		else
			c = ptr - 10 + 'a';
		write(1, &c, 1);
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
			{
				write(1, "0x", 2);
				counter += 2;
				ft_putptr(va_arg(args, void *), &counter);
			}
			else if (format[i] == 'd')
				ft_putnbr(va_arg(args, int), &counter);
			else if (format[i] == 'i')
				ft_putnbr(va_arg(args, int), &counter);
			else if (format[i] == 'u')
				ft_putunsnbr(va_arg(args, unsigned int), &counter);
			else if (format[i] == 'x')
				ft_puthex(va_arg(args, unsigned int), &counter, format[i]);
			else if (format[i] == 'X')
				ft_puthex(va_arg(args, unsigned int), &counter, format[i]);
			else if (format[i] == '%')
				ft_putchar('%', &counter);
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
	char 			*ptr;
	int				number;
	int				number2;
	unsigned int	number3;
	char	s[20] = "! Welcome";

	c = '!';
	number = -2147483648;
	number2 = 2147483647;
	number3 = 4294967295;
	ptr = s;

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

	//Test for %x
	ft_printf("\n%x\n", number3);
	printf("original return - %d\n", printf("\n%x\n", number3));

	//Test for %X
	ft_printf("\n%X\n", number3);
	printf("original return - %d\n", printf("\n%X\n", number3));

	//Test for %p
	ft_printf("\n%p\n", ptr);
	printf("original return - %d\n", printf("\n%p\n", ptr));
}
