/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:47:26 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:52:04 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end >= 0 && ft_strchr(set, s1[end]) != NULL)
		end--;
	if (s1[0] == '\0' || end < 0)
	{
		dest = ft_calloc(1, 1);
		return (dest);
	}
	dest = ft_calloc(end - start + 2, 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (start <= end)
		dest[i++] = s1[start++];
	return (dest);
}
