/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:58:31 by adprzyby          #+#    #+#             */
/*   Updated: 2023/11/17 14:12:51 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;
	size_t	size;

	i = 0;
	size = (ft_strlen(s));
	dest = (char *)malloc(size + 1);
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[size] = '\0';
	return (dest);
}
