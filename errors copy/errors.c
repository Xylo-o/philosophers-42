/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:14:01 by adprzyby          #+#    #+#             */
/*   Updated: 2024/06/17 17:49:18 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

int	handle_err(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Please insert correct number of arguments\n");
		return (-1);
	}
	else if (ft_atoi(argv[1]) > 200)
	{
		printf("Please insert max 200 philos...\n");
		return (-1);
	}
	return (0);
}
