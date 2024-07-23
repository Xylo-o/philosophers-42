/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:01:11 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/18 18:58:52 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+')
	{
		sign = 1;
		nptr++;
	}
	else if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

void	lock_forks(t_env *env, int left_fork, int right_fork)
{
	if (left_fork < right_fork)
	{
		pthread_mutex_lock(&env->forks[left_fork].f_lock);
		pthread_mutex_lock(&env->forks[right_fork].f_lock);
	}
	else
	{
		pthread_mutex_lock(&env->forks[right_fork].f_lock);
		pthread_mutex_lock(&env->forks[left_fork].f_lock);
	}
}

int	check_meals(t_env *env, int min_meal_count)
{
	if (env->meals_needed != -1 && (min_meal_count >= env->meals_needed))
	{
		env->dead = 1;
		pthread_mutex_unlock(&env->monitor);
		return (1);
	}
	pthread_mutex_unlock(&env->monitor);
	return (0);
}

int	check_status(t_philo *philo)
{
	t_env	*env;
	int		continue_loop;

	env = philo->env;
	pthread_mutex_lock(&env->monitor);
	continue_loop = !(env->dead);
	pthread_mutex_unlock(&env->monitor);
	return (continue_loop);
}

void	set_exit(t_env *env, t_philo *philo)
{
	env->dead = 1;
	pthread_mutex_unlock(&env->monitor);
	pthread_mutex_lock(&env->print_lock);
	printf("%u %d died\n", get_time(), philo->id);
	pthread_mutex_unlock(&env->print_lock);
}
