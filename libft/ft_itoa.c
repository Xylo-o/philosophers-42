/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:12:49 by adprzyby          #+#    #+#             */
/*   Updated: 2023/11/21 18:46:56 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	converter(int n, char *arr)
{
	if (n < 0)
	{
		*arr = (n % 10) * -1 + '0';
	}
	else
	{
		*arr = (n % 10) + '0';
	}
}

static int	src_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	if (n > 0)
		n *= -1;
	if (n % 10 == 0)
		n--;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*str;
	char	*str_end_it;

	size = src_size(n);
	str = malloc(size + 1);
	str_end_it = str + size;
	if (!str)
		return (NULL);
	sign = 0;
	if (n < 0)
		sign = 1;
	*str_end_it = '\0';
	str_end_it--;
	while (str <= str_end_it)
	{
		converter(n, str_end_it);
		str_end_it--;
		n /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
