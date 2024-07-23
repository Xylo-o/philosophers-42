/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:01:58 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/18 18:58:52 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_think(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	pthread_mutex_lock(&env->monitor);
	pthread_mutex_lock(&env->print_lock);
	if (!(env->dead))
		printf("%u %d is thinking\n", get_time(), philo->id);
	pthread_mutex_unlock(&env->print_lock);
	pthread_mutex_unlock(&env->monitor);
}
