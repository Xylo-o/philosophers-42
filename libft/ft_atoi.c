/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:04:09 by adprzyby          #+#    #+#             */
/*   Updated: 2024/04/15 21:38:08 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1.Skipping "white signs" with external function
// 2. Recognizing +\- signs
// 3. Parsing numbers and counting the output

#include "libft.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*nptr) == 1)
	{
		nptr++;
	}
	if (*nptr == '+')
	{
		sign = 1;
		nptr++;
	}
	else if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}
