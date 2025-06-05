/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:44:49 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/06 02:15:44 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_philos_for_dinner(philo->table);
	set_long(&philo->philo_mutex, philo->last_meal_time,
		current_time("MILLISECOND"));
	logging(&philo, "TAKEFORK");
	monitor_start(philo->table);
	while (!get_bool(philo->table->is_dinner_end) == true)
		usleep(200);
	return (NULL);
}
static void	set_philos_for_dinner(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
		safe_thread_op(&table->philo[i].philo_thread, &routine, "CREATE");
	set_bool(&table->table_mutex, table->is_philos_ready, true);
}
void	dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->number_of_limit_meals == 0)
		return ;
	if (table->philo_nbr == 1)
		safe_thread_op(&table->philo[i].philo_thread, &one_philo, "CREATE");
	;
	set_philos_for_dinner(&table);
	monitor_start(&table);
	while (get_bool(&table->table_mutex, table->is_philos_ready) == true)
		;
	table->time_for_sim_start = current_time("MILLISECOND");
	while (++i < table->philo_nbr)
		safe_thread_op(&table->philo[i].philo_thread, NULL, "JOIN");
}
void	*routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;

	philo = (t_philo *)arg; // pointerı pointera eşitlemis oldum
	table = philo->table;
	safe_increase_long(&table->table_mutex, &table->threads_nbr);
	while (!get_bool(&table->table_mutex, &table->is_dinner_end))
	{
		take_forks(philo);
		if (get_bool(&table->table_mutex, table->philo->hunger_status) == false)
			eat(philo);
		else
		{
			sleeping(philo);
			thinking(philo);
		}
	}
}
