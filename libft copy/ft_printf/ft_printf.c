/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:51 by adprzyby          #+#    #+#             */
/*   Updated: 2023/11/30 18:56:28 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length = ft_printchar(va_arg(args, int));
	else if (format == 's')
		length = ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		length = ft_printptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		length = ft_printnum(va_arg(args, int));
	else if (format == 'u')
		length = ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length = ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		length = ft_printprocent();
	return (length);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		length;
	int		i;

	va_start(args, s);
	length = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			length += ft_format(args, s[i + 1]);
			if (length == -1)
				return (-1);
			i++;
		}
		else
			length += ft_printchar(s[i]);
		if (length == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (length);
}
