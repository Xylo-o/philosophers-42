/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:49:44 by adprzyby          #+#    #+#             */
/*   Updated: 2024/06/17 19:30:47 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/philo.h"

int main(int argc, char **argv)
{
	t_env	*env;
	if (handle_err(argc, argv) == -1)
		return (1);										// TODO input error handling
	env = init_env(argv);
	if (!env)
	{
		printf("Nicht gut!\n");
		return (1);
	}
	printf("Alles gut!\n");
	create_philos(env);
	printf("Ja woll!\n");
	return (0);
}
