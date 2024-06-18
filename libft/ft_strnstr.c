/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:12:42 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:51:46 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ndl[0] == '\0')
	{
		return ((char *)hay);
	}
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == ndl[j] && i + j < len && ndl[j] != '\0')
		{
			j++;
		}
		if (ndl[j] == '\0')
		{
			return ((char *)&hay[i]);
		}
		i++;
	}
	return (NULL);
}
