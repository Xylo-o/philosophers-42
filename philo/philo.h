/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:50:11 by adprzyby          #+#    #+#             */
/*   Updated: 2024/07/18 18:58:32 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// INCLUDES

# include <errno.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// STRUCTS

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	uint32_t		last_meal_time;
	pthread_mutex_t	p_lock;
	pthread_t		thread;
	struct s_env	*env;
}					t_philo;

typedef struct s_fork
{
	int				taken;
	pthread_mutex_t	f_lock;
}					t_fork;

typedef struct s_env
{
	int				num_philos;
	uint32_t		time_to_die;
	uint32_t		time_to_eat;
	uint32_t		time_to_sleep;
	int				meals_needed;
	int				min_meal_count;
	int				dead;
	t_philo			*philos;
	t_fork			*forks;
	pthread_t		death;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	monitor;
	pthread_mutex_t	taken_lock;
}					t_env;

// FUNCTIONS

//*init
t_env				*init_env(char **data);
void				init_philos(t_env *env);
void				init_forks(t_env *env);
void				init_times(t_env *env, char **argv);
void				init_mutexes(t_env *env);
//*process
void				*routine(void *arg);
void				*monitor(void *arg);
int					run_env(t_env *env);
int					join_threads(t_env *env);
//*errors
int					handle_err(int argc, char **argv);
int					is_positive_number(char *str);
void				free_mutex(t_env *env);
void				free_env(t_env *env);
void				free_all(t_env *env);
//*eating
void				f_eat(t_philo *philo);
int					wait_for_fork(t_env *env, t_philo *philo, int left_fork,
						int right_fork);
int					take_forks(t_env *env, t_philo *philo, int left_fork,
						int right_fork);
//*sleeping
void				f_sleep(t_philo *philo);
//*thinking
void				f_think(t_philo *philo);
//*time
uint32_t			get_time(void);
void				ft_usleep(uint32_t time);
//*utils
int					ft_atoi(const char *nptr);
void				lock_forks(t_env *env, int left_fork, int right_fork);
int					check_meals(t_env *env, int min_meal_count);
void				set_exit(t_env *env, t_philo *philo);
int					check_status(t_philo *philo);

#endif