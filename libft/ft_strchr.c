/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:58:57 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:50:34 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	const char		*p_src = s;
	size_t			i;

	uc = (unsigned char)c;
	i = 0;
	while (p_src[i] != '\0')
	{
		if (p_src[i] == uc)
		{
			return ((char *)&p_src[i]);
		}
		i++;
	}
	if (uc == '\0')
	{
		return ((char *)&p_src[i]);
	}
	return (NULL);
}
