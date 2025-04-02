/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:31:29 by tomsato           #+#    #+#             */
/*   Updated: 2025/03/23 23:50:51 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/*macro*/
# define STD_OUT 1
# define HEX_BIG "0123456789ABCDEF"
# define HEX_SMALL "0123456789abcdef"
/*include*/
# include "../../libft/libft.h"
# include <stdarg.h>
/*typedef*/
typedef int	(*t_format_func)(va_list);

/*ft_printf.c*/
void		init_format_func(t_format_func *format_func);
int			handle_format(char format, va_list args);
int			ft_printf(const char *format, ...);
/*format_cs.c*/
int			format_c(va_list args);
int			format_s(va_list args);
/*format_p.c*/
size_t		get_memlen(void *ptr);
size_t		put_memaddr(void *ptr, char *hex);
int			format_p(va_list args);
/*format.di.c*/
int			get_int_len(long n);
int			format_d(va_list args);
int			format_i(va_list args);
/*format_u.c*/
int			get_ulong_len(unsigned long n);
int			get_uint_len(unsigned int n);
void		ft_putul(unsigned long int u);
int			format_u(va_list args);
/*format_xX.c*/
void		put_hex(unsigned long int hex, char *hex_table);
int			format_smallx(va_list args);
int			format_bigx(va_list args);
/*format_percent.c*/
int			format_percent(va_list args);

#endif
