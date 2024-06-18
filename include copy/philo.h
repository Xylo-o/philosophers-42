/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:50:11 by adprzyby          #+#    #+#             */
/*   Updated: 2024/06/17 19:33:33 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

// INCLUDES

# include "../libft/libft.h"
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

// STRUCTS

enum state
{
	SLEEP,
	EAT,
	THINK
};

typedef struct s_env
{
	int	state;     // 0 - sleep, 1 - eat, 2 - sleep
	int id;
	int forks;  	// amount of forks he has
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int not_pme;		// Number of times philo must eat
	int philo;	// amount of philo in total
	int dead;	// flag if someone is dead
}t_env;

typedef struct s_fork
{
	int id;
	int in_use;
	pthread_mutex_t mutex;
} t_fork;

// FUNCTIONS

//*init
t_env	*init_env(char **data);
int	init_table(int num_of_philo, t_env *env);
int	init_philos(int num_of_p, char **data, t_env *env);
int	init_forks(int num_of_forks);
int	init_times(char **data, t_env *env);
//*process
void	create_philos(t_env *env);
void	*routine(void *arg);
//*errors
int	handle_err(int argc, char **argv);


#endif