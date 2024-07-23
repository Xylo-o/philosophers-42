/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:01:10 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/18 18:58:52 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_env *env, t_philo *philo, int left_fork, int right_fork)
{
	env->forks[right_fork].taken = 1;
	env->forks[left_fork].taken = 1;
	pthread_mutex_lock(&env->monitor);
	pthread_mutex_lock(&env->print_lock);
	if (!env->dead)
	{
		printf("%u %d has taken a fork\n", get_time(), philo->id);
		printf("%u %d has taken a fork\n", get_time(), philo->id);
		printf("%u %d is eating\n", get_time(), philo->id);
		pthread_mutex_unlock(&env->print_lock);
		pthread_mutex_unlock(&env->monitor);
		return (0);
	}
	pthread_mutex_unlock(&env->print_lock);
	pthread_mutex_unlock(&env->monitor);
	return (1);
}

int	wait_for_fork(t_env *env, t_philo *philo, int left_fork, int right_fork)
{
	while (1)
	{
		pthread_mutex_lock(&env->monitor);
		if (env->dead)
		{
			if (env->num_philos > 1)
			{
				pthread_mutex_unlock(&env->forks[left_fork].f_lock);
				pthread_mutex_unlock(&env->forks[right_fork].f_lock);
			}
			pthread_mutex_unlock(&env->monitor);
			return (1);
		}
		pthread_mutex_unlock(&env->monitor);
		if ((left_fork != right_fork) && (!env->forks[left_fork].taken
				&& !env->forks[right_fork].taken))
		{
			if (take_forks(env, philo, left_fork, right_fork) == 1)
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

void	f_eat(t_philo *philo)
{
	t_env	*env;
	int		left_fork;
	int		right_fork;

	env = philo->env;
	left_fork = philo->id - 1;
	right_fork = philo->id % env->num_philos;
	if (env->num_philos > 1)
		lock_forks(env, left_fork, right_fork);
	if (wait_for_fork(env, philo, left_fork, right_fork) == 1)
		return ;
	pthread_mutex_lock(&env->monitor);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&env->monitor);
	ft_usleep(env->time_to_eat);
	env->forks[right_fork].taken = 0;
	env->forks[left_fork].taken = 0;
	pthread_mutex_unlock(&env->forks[left_fork].f_lock);
	pthread_mutex_unlock(&env->forks[right_fork].f_lock);
	pthread_mutex_lock(&env->monitor);
	philo->meals_eaten++;
	pthread_mutex_unlock(&env->monitor);
}
