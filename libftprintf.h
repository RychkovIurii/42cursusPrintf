/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:45:55 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/06 15:53:53 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_putunsnbr(unsigned int n, int *counter);
void	ft_puthex(unsigned int n, int *counter, char format);
void	ft_putptr(void *p, int *counter);
int		ft_printf(const char *format, ...);

#endif