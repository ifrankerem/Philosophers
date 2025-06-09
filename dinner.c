/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:44:49 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/09 20:11:11 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philos_for_dinner(t_table *table)
{
	while (get_bool(&table->table_mutex, &table->is_philos_ready) == false)
		;
}
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

void	dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->number_of_limit_meals == 0)
		return ;
	table->time_for_sim_start = current_time("MILLISECOND");
	if (table->philo_nbr == 1)
	{
		safe_thread_op(&table->philo[0].philo_thread, &one_philo,
			&table->philo[0], "CREATE");
		set_bool(&table->table_mutex, &table->is_philos_ready, true);
		monitor_start(table);
		safe_thread_op(&table->philo[0].philo_thread, NULL, NULL, "JOIN");
		return ;
	}
	while (++i < table->philo_nbr)
	{
		safe_thread_op(&table->philo[i].philo_thread, &routine,
			&table->philo[i], "CREATE");
		set_long(&table->philo[i].philo_mutex, &table->philo[i].last_meal_time,
			table->time_for_sim_start);
	}
	set_bool(&table->table_mutex, &table->is_philos_ready, true);
	monitor_start(table);
	i = -1;
	while (++i < table->philo_nbr)
		safe_thread_op(&table->philo[i].philo_thread, NULL, NULL, "JOIN");
}

void	*routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;

	philo = (t_philo *)arg; // pointerı pointera eşitlemis oldum
	table = philo->table;
	set_philos_for_dinner(table);
	safe_increase_long(&table->table_mutex, &table->threads_nbr);
	while (!get_bool(&table->table_mutex, &table->is_dinner_end))
	{
		if (get_bool(&philo->philo_mutex, &philo->hunger_status) == true)
			break ;
		eat(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
