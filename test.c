/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:30:32 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 16:35:14 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char			c;
	char 			*ptr2;
	int				number;
	int				number2;
	unsigned int	number3;
	int				number4;
	char	s[20] = "! Welcome";
	void *ptr = NULL;

	c = '!';
	number = -2147483648;
	number2 = 2147483647;
	number3 = 4294967295;
	number4 = -1;
	ptr2 = s;

	//Test for %c
	ft_printf("mine return - %d\n", ft_printf("Hello Iurii%c\n", c));
	printf("original return - %d\n", printf("Hello Iurii%c\n", c));

	//Test for %s
	ft_printf("mine return - %d\n", ft_printf("\nHello Iurii%s\n", s));
	printf("original return - %d\n", printf("\nHello Iurii%s\n", s));

	//Test for %d
	ft_printf("mine return - %d\n", ft_printf("\n%d %d\n", number, number4));
	printf("original return - %d\n", printf("\n%d %d\n", number, number4));

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
	ft_printf("mine return - %d\n", ft_printf("\n%p\n", ptr2));
	printf("original return - %d\n", printf("\n%p\n", ptr2));

	//Test for %%
	ft_printf("mine return - %d\n", ft_printf("%%"));
	printf("original return - %d\n", printf("%%"));

	//Test for ""
	ft_printf("mine return - %d\n", ft_printf(""));
	printf("original return - %d\n", printf(""));

	printf ("%s \n", "A string");
	ft_printf ("%s \n", "A string");
	printf ("Characters: %c %c \n", 'a', 65);
	ft_printf ("Characters: %c %c \n", 'a', 65);
	printf ("Strings: %s%c%s \n", "Hello", ' ', "World");
	ft_printf ("Strings: %s%c%s \n", "Hello", ' ', "World");
	printf ("Digits: %d%d%d \n", 1, 33, 7);
	ft_printf ("Digits: %d%d%d \n", 1, 33, 7);
	printf ("Digits: %% \n");
	ft_printf ("Digits: %% \n");
	printf ("Digits: %x%X \n", 42, 42);
	ft_printf ("Digits: %x%X \n", 42, 42);

	printf("\n\n");
	ft_printf("Return value check for strings. Should be %d, is %d\n", printf ("Strings: %s%c%s \n", "Hello", ' ', "World"), ft_printf ("Strings: %s%c%s \n", "Hello", ' ', "World"));
	printf("\n\n");
	ft_printf("Return value check for strings. Should be %d, is %d\n", printf ("Strings: %s%c%c%d%s \n", "Hello", ' ', ' ', 1, "World"), ft_printf ("Strings: %s%c%c%d%s \n", "Hello", ' ', ' ', 1, "World"));
	printf("\n\n");
	printf("Return value check for numbers. Original return value is %d\n", printf ("Digits: %d%d%d \n", 1, 33, 7));
	printf("Return value check for numbers. Ftprintf return value is %d\n", ft_printf ("Digits: %d%d%d \n", 1, 33, 7));

	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("Digits: %d\n", 1234567));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("Digits: %d\n", 1234567));
	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%d\n", 1));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%d\n", 1));
	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%d%d\n", 1, 1));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%d%d\n", 1, 1));
	printf("\n\n");
	ft_printf("Return value check for char. Original return value is '%d'\n", printf ("%c%c\n", 'a', 'a'));
	ft_printf("Return value check for char. Ftprintf return value is '%d'\n", ft_printf ("%c%c\n", 'a', 'a'));
	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%x%x\n", 111111111, 111));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%x%x\n", 111111111, 111));
	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%X%X\n", -111111111, -111));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%X%X\n", -111111111, -111));
	printf("\n\n");
	printf("Return value check for numbers. Original return value is '%d'\n", printf ("%u\n", 1));
	printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%u\n", 1));
	printf("\n\n");
	ft_printf("Return value check for &ptr addr. Original return value is '%d'\n", printf ("%p\n", &ptr));
	ft_printf("Return value check for &ptr addr. Ftprintf return value is '%d'\n", ft_printf ("%p\n", &ptr));
	printf("\n\n");
	ft_printf("Return value check for ptr addr. Original return value is '%d'\n", printf ("%p\n", ptr));
	ft_printf("Return value check for ptr addr. Ftprintf return value is '%d'\n", ft_printf ("%p\n", ptr));
	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%i\n", -011));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%i\n", -011));
	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%i\n", -011));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%i\n", -011));
	printf("\n\n");
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%s\n", (char *)NULL));
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%s\n", (char *)NULL));
	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf("\001\002\007\v\010\f\r\n"));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf("\001\002\007\v\010\f\r\n"));
	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n", printf("%%\n"));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf("%%\n"));
	printf("\n\n");
	ft_printf("Return value check for numbers. Original return value is '%d'\n",  printf(" %c\n", 'x'));
	ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n",  ft_printf(" %c\n", 'x'));
	printf("\n\n");
	ft_printf("Return value check for ptr addr and null char. Original return value is '%d'\n", printf ("%p\n", (char *)NULL));
	ft_printf("Return value check for ptr addr and null char. Ftprintf return value is '%d'\n", ft_printf ("%p\n", (char *)NULL));
	return 0;
}