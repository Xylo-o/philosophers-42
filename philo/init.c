/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:49:37 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/08 18:05:27 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_env	*init_env(char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->num_philos = ft_atoi(argv[1]);
	init_times(env, argv);
	if (argv[5])
		env->meals_needed = ft_atoi(argv[5]);
	else
		env->meals_needed = -1;
	env->min_meal_count = INT32_MAX;
	env->dead = 0;
	env->philos = malloc(sizeof(t_philo) * env->num_philos);
	if (!env->philos)
		return (NULL);
	env->forks = malloc(sizeof(t_fork) * env->num_philos);
	if (!env->forks)
		return (NULL);
	init_mutexes(env);
	return (env);
}

void	init_philos(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->num_philos)
	{
		env->philos[i].id = i + 1;
		env->philos[i].meals_eaten = 0;
		env->philos[i].last_meal_time = get_time();
		env->philos[i].env = env;
		pthread_mutex_init(&env->philos[i].p_lock, NULL);
		i++;
	}
}

void	init_forks(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->num_philos)
	{
		pthread_mutex_init(&env->forks[i].f_lock, NULL);
		i++;
	}
}

void	init_times(t_env *env, char **argv)
{
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
}

void	init_mutexes(t_env *env)
{
	pthread_mutex_init(&env->print_lock, NULL);
	pthread_mutex_init(&env->monitor, NULL);
	pthread_mutex_init(&env->taken_lock, NULL);
}
