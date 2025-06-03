/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:16:40 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/03 05:06:34 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_table *table)
{
	int	i;

	i = -1;
	table->forks = safe_malloc(sizeof(t_forks) * table->philo_nbr);
	while (++i < table->philo_nbr)
	{
		table->forks[i].fork_id = i;
		safe_mutex(&table->forks[i].fork, "INIT");
	}
}
static void	init_philos(t_table *table)
{
	int	i;

	table->philo = safe_malloc(sizeof(t_philo) * table->philo_nbr);
	i = -1;
	while (++i < table->philo_nbr)
	{
		table->philo[i].table = table;
		table->philo[i].philo_id = i + 1;
		// philo id 1 den baslasın diye hem de cıktı için
		table->philo[i].meals_eaten = 0;
		table->philo[i].status = false;
		//* buna gelicem burda ac tok kontrolu yapmalıyım false = aç true ise suan yiyor olmalı
		table->philo[i].right_fork = i;
		table->philo[i].left_fork = (i + 1) % table->philo_nbr;
	}
}

void	data_init(t_table *table)
{
	safe_mutex(&table->table_mutex, "INIT");
	safe_mutex(&table->log_mutex, "INIT");
	set_bool(table, table->is_dinner_end, false);
	init_forks(table);
	init_philos(table);
}