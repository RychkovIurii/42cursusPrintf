# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 16:00:25 by irychkov          #+#    #+#              #
#    Updated: 2024/05/07 18:29:14 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_printf.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_nbr.c \
		ft_print_unsnbr.c \
		ft_print_hex.c \
		ft_print_ptr.c \
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