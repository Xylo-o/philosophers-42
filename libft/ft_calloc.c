/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:01:52 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:45:52 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elem, size_t size)
{
	char	*memory;
	int		fullsize;

	fullsize = elem * size;
	memory = (char *)malloc(elem * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, fullsize);
	return (memory);
}
