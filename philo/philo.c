/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:49:44 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/08 18:05:31 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	if (handle_err(argc, argv) == -1)
		return (1);
	env = init_env(argv);
	if (!env)
		return (1);
	init_philos(env);
	init_forks(env);
	run_env(env);
	join_threads(env);
	free_all(env);
	return (0);
}
