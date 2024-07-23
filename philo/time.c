/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:57:17 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/18 18:58:32 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint32_t	get_time(void)
{
	static long long	start_time = -1;
	struct timeval		tv;
	uint32_t			current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	if (start_time == -1)
		start_time = current_time;
	return (current_time - start_time);
}

void	ft_usleep(uint32_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(500);
}
