/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:34:20 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:52:09 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s);
	if (start >= size)
	{
		dest = malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (start + len > size)
	{
		len = size - start;
	}
	s = s + start;
	dest = malloc(len + 1);
	if (!dest)
	{
		return (NULL);
	}
	ft_memcpy(dest, s, len);
	dest[len] = '\0';
	return (dest);
}
