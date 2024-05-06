/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/06 18:28:48 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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
	//validation for format?
	counter = 0;
	ft_helper(format, args, &counter);
	va_end(args);
	return (counter);
}

/*
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
	ft_printf("mine return - %d\n", ft_printf("Hello Iurii%c\n", c));
	printf("original return - %d\n", printf("Hello Iurii%c\n", c));

	//Test for %s
	ft_printf("mine return - %d\n", ft_printf("\nHello Iurii%s\n", s));
	printf("original return - %d\n", printf("\nHello Iurii%s\n", s));

	//Test for %d
	ft_printf("mine return - %d\n", ft_printf("\n%d\n", number));
	printf("original return - %d\n", printf("\n%d\n", number));

	//Test for %i
	ft_printf("mine return - %d\n", ft_printf("\n%i\n", number2));
	printf("original return - %d\n", printf("\n%i\n", number2));

	//Test for %u
	ft_printf("mine return - %d\n", ft_printf("\n%u\n", number3));
	printf("original return - %d\n", printf("\n%u\n", number3));

	//Test for %x
	ft_printf("mine return - %d\n", ft_printf("\n%x\n", number3));
	printf("original return - %d\n", printf("\n%x\n", number3));

	//Test for %X
	ft_printf("mine return - %d\n", ft_printf("\n%X\n", number3));
	printf("original return - %d\n", printf("\n%X\n", number3));

	//Test for %p
	ft_printf("mine return - %d\n", ft_printf("\n%p\n", ptr));
	printf("original return - %d\n", printf("\n%p\n", ptr));

	//Test for %%
	ft_printf("mine return - %d\n", ft_printf("%%"));
	printf("original return - %d\n", printf("%%"));

	//Test for ""
	ft_printf("mine return - %d\n", ft_printf(""));
	printf("original return - %d\n", printf(""));

	//Test for error
	ft_printf("mine return - %d\n", ft_printf("%d"));
	//printf("original return - %d\n", printf("%d"));	CHECK ERROR. Original function has diff behavior.

}
*/