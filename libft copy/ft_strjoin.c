/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:20:42 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/25 17:18:50 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*dest;
	size_t	i;
	size_t	j;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = (char *)malloc(size_s1 + size_s2 + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size_s2)
	{
		dest[i++] = s2[j++];
	}
	dest[i] = '\0';
	return (dest);
}
