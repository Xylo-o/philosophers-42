/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:45:13 by adprzyby          #+#    #+#             */
/*   Updated: 2023/11/30 19:41:54 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_printchar(int c);
int		ft_printnum(int n);
int		ft_printunsigned(unsigned int n);
int		ft_printhex(unsigned long n, const char format);
int		ft_printptr(unsigned long n);
int		ft_printstr(char *s);
int		ft_printprocent(void);

#endif