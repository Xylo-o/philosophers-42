/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:38:41 by adprzyby          #+#    #+#             */
/*   Updated: 2023/11/28 19:43:06 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (ft_printchar((int)s[i]) == -1)
			return (-1);
		else
			i++;
	}
	return (i);
}

int	ft_printprocent(void)
{
	if (write (1, "%", 1) == -1)
		return (-1);
	return (1);
}
