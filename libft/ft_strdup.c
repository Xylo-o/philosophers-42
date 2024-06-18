/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:29:21 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:50:41 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s);
	dest = (char *)malloc(size + 1);
	if (!dest)
	{
		return (NULL);
	}
	ft_memcpy(dest, s, size + 1);
	return ((char *)dest);
}
