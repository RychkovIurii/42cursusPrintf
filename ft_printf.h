/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:45:55 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/07 18:35:57 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_print_char(char c, int *counter, int *check_write);
void	ft_print_str(char *s, int *counter, int *check_write);
void	ft_print_nbr(int n, int *counter, int *check_write);
void	ft_print_unsnbr(unsigned int n, int *counter, int *check_write);
void	ft_print_hex(unsigned int n,
			int *counter, char format, int *check_write);
void	ft_print_ptr(void *p, int *counter, int *check_write);
int		ft_printf(const char *format, ...);

#endif