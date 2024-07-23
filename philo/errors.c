/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:14:01 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/20 13:36:10 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_err(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("Please insert correct number of arguments\n");
		return (-1);
	}
	while (i < argc)
	{
		if (!is_positive_number(argv[i]))
		{
			printf("Please insert only positive numbers\n");
			return (-1);
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
	{
		printf("Please insert correct values...\n");
		return (-1);
	}
	return (0);
}

int	is_positive_number(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(str) < 0)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	free_mutex(t_env *env)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&env->print_lock);
	pthread_mutex_destroy(&env->monitor);
	pthread_mutex_destroy(&env->taken_lock);
	while (i < env->num_philos)
	{
		if (pthread_mutex_destroy(&env->forks[i].f_lock) != 0)
		{
			printf("Error: fork(%i) mutex destruction failed\n", i);
			break ;
		}
		if (pthread_mutex_destroy(&env->philos[i].p_lock) != 0)
		{
			printf("Error: philo(%i) mutex destruction failed\n", i);
			break ;
		}
		i++;
	}
}

void	free_env(t_env *env)
{
	free(env->philos);
	free(env->forks);
	free(env);
}

void	free_all(t_env *env)
{
	free_env(env);
	free_mutex(env);
}
