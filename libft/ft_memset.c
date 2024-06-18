/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:54:32 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:49:13 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p_str;
	unsigned char	ch;
	size_t			i;

	p_str = str;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p_str[i] = ch;
		i++;
	}
	return (str);
}
