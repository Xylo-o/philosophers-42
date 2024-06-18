/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:11:42 by adprzyby          #+#    #+#             */
/*   Updated: 2024/06/17 19:44:20 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

void	create_philos(t_env *env)
{
	pthread_t	*curr_philo = malloc(sizeof(pthread_t) * env->philo);
	if (!curr_philo)
		return ;				//TODO check if this is enough
	int i = 0;
	while (i < env->philo)
	{
		if (pthread_create(&curr_philo[i], NULL, routine, (env->time_to_die)) != 0)
			return ;
		env->id = i;
		i++;
	}			//TODO join threads here?
}

void	*routine(void *arg)
{
	int cycle;

	cycle = (int)arg;
	while(cycle)
	{
		// eat();
		// think();
		printf("Jem zupe\n");
		cycle--;
	}
	return NULL;
}
