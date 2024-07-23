/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:11:42 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/20 13:18:24 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_env(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->num_philos)
	{
		if (pthread_create(&env->philos[i].thread, NULL, routine,
				(void *)&env->philos[i]) != 0)
		{
			printf("Error: Thread creation failed\n");
			return (1);
		}
		i++;
	}
	if (pthread_create(&env->death, NULL, monitor, env) != 0)
	{
		printf("Error: Thread creation failed\n");
		return (1);
	}
	return (0);
}

int	join_threads(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->num_philos)
	{
		if (pthread_join(env->philos[i].thread, NULL) != 0)
		{
			printf("Error: Thread joining failed\n");
			return (1);
		}
		i++;
	}
	if (pthread_join(env->death, NULL) != 0)
	{
		printf("Error: Thread joining failed\n");
		return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->env->time_to_eat / 2);
	while (1)
	{
		if (!check_status(philo))
			break ;
		f_think(philo);
		if (!check_status(philo))
			break ;
		f_eat(philo);
		if (!check_status(philo))
			break ;
		f_sleep(philo);
		if (!check_status(philo))
			break ;
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_env		*env;
	int			i;
	int			min_meal_count;

	env = (t_env *)arg;
	i = 0;
	while (1)
	{
		i = i % env->num_philos;
		min_meal_count = INT32_MAX;
		pthread_mutex_lock(&env->monitor);
		while (i < env->num_philos)
		{
			if (env->philos[i].meals_eaten < min_meal_count)
				min_meal_count = env->philos[i].meals_eaten;
			if ((get_time() - env->philos[i].last_meal_time) > env->time_to_die)
				return (set_exit(env, &env->philos[i]), NULL);
			i++;
		}
		if (check_meals(env, min_meal_count) == 1)
			return (NULL);
	}
	return (NULL);
}
