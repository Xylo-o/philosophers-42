/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:22:56 by adprzyby          #+#    #+#             */
/*   Updated: 2023/11/30 18:53:35 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (n < 0)
		{
			if (write(1, "-", 1) == -1)
				return (-1);
			n = -n;
		}
		if (n <= 9)
		{
			n = n + '0';
			if (write(1, &n, 1) == -1)
				return (-1);
		}
		else
		{
			if (ft_putnbr(n / 10) == -1)
				return (-1);
			if (ft_putnbr(n % 10) == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_printnum(int n)
{
	if (ft_putnbr(n) == -1)
		return (-1);
	return (ft_num_len(n));
}

int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_printunsigned(unsigned int n)
{
	int	length;

	length = ft_unsigned_len(n);
	if (n == 0)
	{
		if (write(1, &"0", 1) == -1)
			return (-1);
		return (1);
	}
	if (n <= 9)
	{
		n = n + '0';
		if (write(1, &n, 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_printunsigned(n / 10) == -1)
			return (-1);
		if (ft_printunsigned(n % 10) == -1)
			return (-1);
	}
	return (length);
}
