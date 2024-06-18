/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:19:04 by adprzyby          #+#    #+#             */
/*   Updated: 2023/11/30 18:28:08 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_writehex(unsigned long n, const char format)
{
	if (n >= 16)
	{
		if (ft_writehex(n / 16, format) == -1)
			return (-1);
		if (ft_writehex(n % 16, format) == -1)
			return (-1);
	}
	else
	{
		if (n <= 9)
		{
			if (ft_printchar(n + '0') == -1)
				return (-1);
		}
		else
		{
			if (format == 'x')
				if (ft_printchar(n - 10 + 'a') == -1)
					return (-1);
			if (format == 'X')
				if (ft_printchar(n - 10 + 'A') == -1)
					return (-1);
		}
	}
	return (0);
}

int	ft_printhex(unsigned long n, const char format)
{
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		else
			return (1);
	}
	else
	{
		if (ft_writehex(n, format) == -1)
			return (-1);
	}
	return (ft_hex_len(n));
}

int	ft_printptr(unsigned long n)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (ft_printhex(n, 'x') + 2);
}
