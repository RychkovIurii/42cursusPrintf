/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:54:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/04/30 09:30:32 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
				ft_putchar(va_arg(args, char));
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
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return 0; //temp not true

}

/* int	main(void)
{
	char	c;

	c = '!';
	ft_printf("Hello Iurii%c", c);
} */