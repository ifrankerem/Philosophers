/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:45:20 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/12 07:01:49 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philo	t_philo;

typedef enum e_time_unit
{
	MILLISECOND,
	MICROSECOND
}						t_time_unit;
typedef enum e_log_unit
{
	TAKEFORK,
	EATING,
	SLEEPING,
	THINKING,
	DIE
}						t_log_unit;

typedef struct forks
{
	long				fork_id;
	pthread_mutex_t		fork;
}						t_forks;
typedef struct table
{
	long				philo_nbr;
	long				time_to_eat;
	long				time_to_die;
	long				time_to_sleep;
	long				number_of_limit_meals;
	long				time_for_sim_start;
	long				threads_nbr;
	t_forks				*forks;
	t_philo				*philo;
	pthread_mutex_t		log_mutex;
	pthread_mutex_t		table_mutex;
	pthread_t			monitor;
	bool				is_philos_ready;
	bool				is_dinner_end;
}						t_table;
typedef struct philo
{
	long				philo_id;
	t_forks				*left_fork;
	t_forks				*right_fork;
	long				meals_eaten;
	long				last_meal_time;
	bool				hunger_status;
	pthread_t			philo_thread;
	t_table				*table;
	pthread_mutex_t		philo_mutex;

}						t_philo;

int						check_args(int argc, char **argv);
void					*ft_error_ptr(char *msg);
long					ft_error_long(char *msg);
int						ft_error_int(char *msg);
void					ft_error_void(char *msg);
int						parsing(t_table *table, char **av);
void					*routine(void *arg);
int						data_init(t_table *table);
void					set_long(pthread_mutex_t *mutex, long *target,
							long value);
void					set_bool(pthread_mutex_t *mutex, bool *target,
							bool value);
long					get_long(pthread_mutex_t *mutex, long *value);
bool					get_bool(pthread_mutex_t *mutex, bool *value);
long					current_time(t_time_unit time_code);
void					better_usleep(long waited_time, t_table *table);
int						dinner(t_table *table);
bool					eat(t_philo *philo);
bool					sleeping(t_philo *philo);
bool					thinking(t_philo *philo);
void					logging(t_philo *philo, t_log_unit action_code);
void					monitor(t_table *table);
void					*monitor_job(void *arg);
void					safe_increase_long(pthread_mutex_t *mutex,
							long *target);
int						clean(t_table *table);

#endif