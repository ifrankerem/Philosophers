#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philo
{
	long			philo_id;
	long			left_fork;
	long			right_fork;
	long			meals_eaten;
	bool			status;
	pthread_t		philo_thread;
	t_table			*table;

}					t_philo;

typedef struct forks
{
	long			*fork_id;
	pthread_mutex_t	fork;
}					t_forks;

typedef struct table
{
	long			philo_nbr;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	long			number_of_limit_meals;
	t_forks			*forks;
	t_philo			*philo;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	table_mutex;
	bool			is_philos_ready;
	bool			is_dinner_end;
}					t_table;

long				ft_error_long(char *msg);
void				*ft_error_ptr(char *msg);
const char			*ft_error_str(char *msg);
int					ft_error_int(char *msg);
void				parsing(t_table *table, char **av);
int					ft_strcmp(char *s1, char *s2);
int					safe_mutex(pthread_mutex_t *mutex, char *flag);
void				*safe_malloc(size_t size);
int					safe_thread_op(pthread_t *th, void *(*func)(void *),
						char *flag);
void				*routine(void *arg);
void				data_init(t_table *table);
void				set_bool(t_table *table, bool *target, bool value);
void				set_long(t_table *table, long *target, long value);
long				get_long(t_table *table, long *value);
bool				get_bool(t_table *table, bool *value);
long				current_time(char *time_code);
void				better_usleep(long waited_time, t_table *table);

#endif