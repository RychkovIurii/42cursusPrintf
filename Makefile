# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 16:00:25 by irychkov          #+#    #+#              #
#    Updated: 2024/05/06 16:28:22 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putunsnbr.c \
		ft_puthex.c \
		ft_putptr.c \
		ft_printf.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

AR = ar rcs

CC = cc

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

.c.o:	
	$(CC) $(CFLAGS) -c -I. $< -o $@

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:	
	rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re