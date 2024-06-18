/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:41:34 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:51:40 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;

	p_s1 = (const unsigned char *)s1;
	p_s2 = (const unsigned char *)s2;
	while (n)
	{
		if (*p_s1 != *p_s2)
		{
			return (*p_s1 - *p_s2);
		}
		if (*p_s1 == '\0')
		{
			return (*p_s1 - *p_s2);
		}
		p_s1++;
		p_s2++;
		n--;
	}
	return (0);
}
