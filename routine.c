/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:44:49 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/04 17:38:38 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philos_for_dinner(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
		safe_thread_op(&table->philo[i].philo_thread, &routine, "CREATE");
	set_bool(table, table->is_philos_ready, true);
}
void	dinner(t_table *table)
{
	if (table->number_of_limit_meals == 0)
		return ;
	if (table->philo_nbr == 1) // TODO add-hoc func özel durum yazcaz
		;
	set_philos_for_dinner(table);
	while (get_bool(table, table->is_philos_ready) == true)
		;
}
void	*routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;

	philo = (t_philo *)arg; // pointerı pointera eşitlemis oldum
	while (!get_bool(table, &table->is_dinner_end))
	{
		take_forks();
		if (get_bool(table, table->philo->status) == false)
			eat(philo);
		else
		{
			sleeping(philo);
			thinking(philo);
		}
	}
}
