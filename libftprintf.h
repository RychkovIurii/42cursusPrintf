/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:45:55 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 17:42:23 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c, int *counter, int *check_write);
void	ft_putstr(char *s, int *counter, int *check_write);
void	ft_putnbr(int n, int *counter, int *check_write);
void	ft_putunsnbr(unsigned int n, int *counter, int *check_write);
void	ft_puthex(unsigned int n, int *counter, char format, int *check_write);
void	ft_putptr(void *p, int *counter, int *check_write);
int		ft_printf(const char *format, ...);

#endif