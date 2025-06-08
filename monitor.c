/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:13:06 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/08 17:12:40 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_philo_dead_full(t_philo *philo)
{
	long	elapsed;

	if (get_bool(&philo->philo_mutex, &philo->hunger_status) == true)
		return (false); // filozof sonuc olarak ölmemis
	elapsed = current_time("MILLISECOND") - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	if (elapsed > (philo->table->time_to_die / 1000))
		return (true);
	return (false);
}
static void	*monitor_job(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (get_bool(&table->table_mutex, &table->is_dinner_end) == false)
	{
		i = -1;
		while (++i < table->philo_nbr && !get_bool(&table->table_mutex,
				&table->is_dinner_end))
		{
			if (is_philo_dead_full(&table->philo[i]) == true)
			{
				set_bool(&table->table_mutex, &table->is_dinner_end, true);
				logging(&table->philo[i], "DIE");
			}
		}
	}
	return (NULL);
}
static bool	is_all_threads_running(t_table *table)
{
	bool	ret_value;

	ret_value = false;
	if (table->threads_nbr == table->philo_nbr)
		ret_value = true;
	return (ret_value);
}
void	monitor_start(t_table *table)
{
	while (!is_all_threads_running(table))
		;
	safe_thread_op(&table->monitor, monitor_job, &table, "CREATE");
}
