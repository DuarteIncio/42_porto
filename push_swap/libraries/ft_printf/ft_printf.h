/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:31:05 by dde-alme          #+#    #+#             */
/*   Updated: 2023/11/02 12:51:40 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int				ft_printf(const char *input, ...);
int				ft_printchar(int c);
int				ft_formats(va_list args, const char format);
int				ft_printstr(char *str);
int				ft_print_hex(unsigned int num, const char format);
int				ft_print_ptr(unsigned long long ptr);
int				ft_printnbr(int x);
int				ft_printpercent(void);
int				ft_print_unsigned(unsigned int x);

void			ft_putstr(char *str);
void			ft_put_hex(unsigned int num, const char format);
int				ft_hex_len(unsigned int num);
int				ft_ptr_len(unsigned long long num);
void			ft_put_ptr(unsigned long long num);
int				ft_num_len(unsigned int num);
char			*ft_uitoa(unsigned int x);

#endif
