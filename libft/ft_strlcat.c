/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:10 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:51:12 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 1. Oblicz długość bufora docelowego
// 2. Skopiuj znaki z src do dst, z uwzględnieniem ograniczenia n
// 3. Dodaj znak null-terminating na końcu
// 4. Zwróć łączną długość źródła i bufora docelowego

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	space_left;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= n)
	{
		return (src_len + n);
	}
	space_left = n - dst_len - 1;
	if (src_len < space_left)
	{
		ft_memcpy(dst + dst_len, src, src_len);
		dst[dst_len + src_len] = '\0';
	}
	else
	{
		ft_memcpy(dst + dst_len, src, space_left);
		dst[dst_len + space_left] = '\0';
	}
	return (dst_len + src_len);
}
