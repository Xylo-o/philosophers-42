/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:49:37 by adprzyby          #+#    #+#             */
/*   Updated: 2024/06/17 18:55:56 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_env	*init_env(char **data)
{
	int	num_of_philo;
	t_env *env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	num_of_philo = ft_atoi(data[1]);
	if (init_table(num_of_philo, env) == -1)
		return (NULL);
	if (init_philos(num_of_philo, data, env) == -1)
		return (NULL);
	if (init_forks(num_of_philo) == -1)
		return (NULL);
	return (env);
}

int	init_table(int num_of_philo, t_env *env)
{
	env->dead = 0;
	env->philo = num_of_philo;
	if (env->philo < 1)
		return (-1);
	env->forks = env->philo;
	return (0);
}

int	init_philos(int num_of_p, char **data, t_env *env)
{
	int		i;

	i = 0;
	while (i < num_of_p)
	{
		env->id = i;
		env->forks = 0;
		env->state = i % 2;
		if (init_times(data, env))
			return (-1);
		if (data[5])
			env->not_pme = ft_atoi(data[5]);
		else
			env->not_pme = 0;
		i++;
	}
	return (0);
}

int	init_times(char **data, t_env *env)
{
	if (!data[2] || !data[3] || !data[4])
		return (-1);
	env->time_to_die = ft_atoi(data[2]);
	env->time_to_eat = ft_atoi(data[3]);
	env->time_to_sleep = ft_atoi(data[4]);
	return (0);
}

int	init_forks(int num_of_forks)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * num_of_forks);
	if (!forks)
		return (-1);
	while (i < num_of_forks)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (0);
}
