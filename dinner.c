/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:44:49 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/11 16:48:28 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		current_time("MILLISECOND"));
	logging(philo, "TAKEFORK");
	safe_increase_long(&philo->table->table_mutex, &philo->table->threads_nbr);
	while (!get_bool(&philo->table->table_mutex, &philo->table->is_dinner_end))
		usleep(500);
	return (NULL);
}
int	dinner2(t_table *table)
{
	int	i;

	i = -1;
	if (pthread_create(&table->monitor, NULL, monitor_job, table) != 0)
		return (ft_error_int("Thread is Failed!"));
	while (++i < table->philo_nbr)
	{
		if (pthread_join(table->philo[i].philo_thread, NULL) != 0)
			return (ft_error_int("Thread is Failed!"));
	}
	set_bool(&table->table_mutex, &table->is_dinner_end, true);
	pthread_join(table->monitor, NULL);
	return (0);
}
int	dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->number_of_limit_meals == 0)
		return (1);
	table->time_for_sim_start = current_time("MILLISECOND");
	if (table->philo_nbr == 1)
	{
		if (pthread_create(&table->philo[0].philo_thread, NULL, &one_philo,
				&table->philo[0]) != 0)
			return (ft_error_int("Thread is Failed!"));
	}
	else
	{
		while (++i < table->philo_nbr)
		{
			if (pthread_create(&table->philo[i].philo_thread, NULL, &routine,
					&table->philo[i]) != 0)
				return (ft_error_int("Thread is Failed!"));
			set_long(&table->philo[i].philo_mutex,
				&table->philo[i].last_meal_time, table->time_for_sim_start);
		}
	}
	set_bool(&table->table_mutex, &table->is_philos_ready, true);
	return (dinner2(table), 0);
}

void	*routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;

	philo = (t_philo *)arg; // pointerı pointera eşitlemis oldum
	table = philo->table;
	while (get_bool(&table->table_mutex, &table->is_philos_ready) == false)
		;
	if (philo->philo_id % 2 != 0)
		usleep(500);
	safe_increase_long(&table->table_mutex, &table->threads_nbr);
	while (!get_bool(&table->table_mutex, &table->is_dinner_end))
	{
		if (eat(philo) == true)
			break ;
		if (sleeping(philo) == true)
			break ;
		if (thinking(philo) == true)
			break ;
	}
	return (NULL);
}
