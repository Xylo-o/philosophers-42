/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:10:55 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:48:01 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p_s1 = s1;
	const unsigned char	*p_s2 = s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (p_s1[i] == p_s2[i])
		{
			i++;
		}
		else
		{
			return (p_s1[i] - p_s2[i]);
		}
	}
	return (0);
}
