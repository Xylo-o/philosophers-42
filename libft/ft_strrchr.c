/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:58:52 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:51:55 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	len;

	ptr = (char *)s;
	len = ft_strlen(ptr) + 1;
	while (len-- != 0)
	{
		if (ptr[len] == (char)c)
		{
			return (&ptr[len]);
		}
	}
	return (0);
}
