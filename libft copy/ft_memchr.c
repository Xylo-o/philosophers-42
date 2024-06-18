/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:29:23 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:47:46 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char		sign;
	const unsigned char	*source = src;
	size_t				i;

	sign = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (source[i] == sign)
		{
			return ((void *)&source[i]);
		}
		i++;
	}
	if (source == NULL)
	{
		return (NULL);
	}
	return (NULL);
}
