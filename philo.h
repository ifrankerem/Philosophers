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

char					*valid(char *av);
void					*ft_error_ptr(char *msg);
long					ft_error_long(char *msg);
int						ft_error_int(char *msg);
void					ft_error_void(char *msg);
int					parsing(t_table *table, char **av);
int						ft_strcmp(char *s1, char *s2);
int						safe_mutex(pthread_mutex_t *mutex, char *flag);
void					*safe_malloc(size_t size);
int						safe_thread_op(pthread_t *th, void *(*func)(void *),
							void *arg, char *flag);
void					*routine(void *arg);
int						data_init(t_table *table);
void					set_long(pthread_mutex_t *mutex, long *target,
							long value);
void					set_bool(pthread_mutex_t *mutex, bool *target,
							bool value);
long					get_long(pthread_mutex_t *mutex, long *value);
bool					get_bool(pthread_mutex_t *mutex, bool *value);
long					current_time(char *time_code);
void					better_usleep(long waited_time, t_table *table);
int						dinner(t_table *table);
bool					eat(t_philo *philo);
bool					sleeping(t_philo *philo);
bool					thinking(t_philo *philo);
void					logging(t_philo *philo, char *action);
void					monitor(t_table *table);
void					monitor_start(t_table *table);
void					*monitor_job(void *arg);
void					safe_increase_long(pthread_mutex_t *mutex,
							long *target);
void					clean(t_table *table);

#endif