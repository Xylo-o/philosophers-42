/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:58:22 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:43:38 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	size;

	i = 0;
	size = (ft_strlen(s));
	while (i < size)
	{
		f(i, &s[i]);
		i++;
	}
	return (0);
}
