/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:48:32 by adprzyby          #+#    #+#             */
/*   Updated: 2023/10/26 20:50:20 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	string_counter(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
	}
	return (count);
}

static int	free_all(char **s, int strings)
{
	int	i;

	i = 0;
	while (i < strings)
	{
		free(s[i]);
		i++;
	}
	free((char *)s);
	return (0);
}

static int	string_len(const char *str, char c, int i)
{
	int	length;

	length = 0;
	while (str[i] && str[i] != c)
	{
		length++;
		i++;
	}
	return (length);
}

static int	copy_chars(char **string_array, char const *s, char c)
{
	int	y;
	int	source_index;
	int	strlen;
	int	x;

	y = 0;
	source_index = 0;
	while (s[source_index] != '\0')
	{
		while (s[source_index] == c)
			source_index++;
		strlen = string_len((const char *)s, c, source_index);
		if (strlen == 0)
			break ;
		string_array[y] = (char *)ft_calloc(strlen + 1, sizeof(char));
		if (string_array[y] == NULL)
			return (free_all(string_array, y));
		x = 0;
		while (x < strlen)
			string_array[y][x++] = s[source_index++];
		y++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		strings;
	char	**string_array;

	if (!s)
		return (NULL);
	strings = string_counter(s, c);
	string_array = (char **)ft_calloc(strings + 1, sizeof(char *));
	if (!string_array)
		return (NULL);
	string_array[strings] = NULL;
	if (!copy_chars(string_array, s, c))
		return (NULL);
	return (string_array);
}
