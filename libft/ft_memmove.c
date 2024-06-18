/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:24:07 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:48:56 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

// 1. Copy data from source to buffer(temp) using while loop
// 2. Set null terminator at the end of the buffer(temp)
// 3. Resetuje licznik
// 4. Copy data from buffer(temp) to destination using while loop

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;
	size_t				i;

	p_src = src;
	p_dest = dest;
	i = 0;
	if (p_dest == p_src || n == 0)
		return (dest);
	if (p_dest < p_src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	}
	return ((char *)dest);
}
