/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:16:40 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/12 11:44:16 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_table *table)
{
	int	i;

	i = -1;
	table->forks = malloc(sizeof(t_forks) * table->philo_nbr);
	if (!table->forks)
		return (ft_error_int("Malloc Error!"));
	while (++i < table->philo_nbr)
	{
		table->forks[i].fork_id = i;
		if (pthread_mutex_init(&table->forks[i].fork, NULL) != 0)
			return (ft_error_int("Mutex Failed!"));
	}
	return (0);
}

static int	init_philos(t_table *table)
{
	int	i;

	table->philo = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!table->philo)
		return (ft_error_int("Malloc Error!"));
	i = -1;
	while (++i < table->philo_nbr)
	{
		table->philo[i].table = table;
		table->philo[i].philo_id = i + 1;
		table->philo[i].meals_eaten = 0;
		table->philo[i].hunger_status = false;
		table->philo[i].left_fork = &table->forks[(i + 1) % table->philo_nbr];
		table->philo[i].right_fork = &table->forks[i];
		if (pthread_mutex_init(&table->philo[i].philo_mutex, NULL) != 0)
			return (ft_error_int("Mutex Failed!"));
	}
	return (0);
}

int	data_init(t_table *table)
{
	if (pthread_mutex_init(&table->table_mutex, NULL) != 0)
		return (ft_error_int("Mutex Failed!"));
	if (pthread_mutex_init(&table->log_mutex, NULL) != 0)
		return (ft_error_int("Mutex Failed!"));
	table->threads_nbr = 0;
	table->is_dinner_end = false;
	table->is_philos_ready = false;
	if (init_forks(table) == 1)
		return (1);
	if (init_philos(table) == 1)
		return (1);
	return (0);
}
