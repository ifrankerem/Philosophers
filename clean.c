/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:40:36 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/06 02:33:05 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_table *table)
{
	t_philo *philo;
	int i;

	philo = table->philo;
	i = -1;
	while (++i < table->philo_nbr)
	{
		safe_mutex(&philo[i].philo_mutex, "DESTROY");
		safe_mutex(&table->forks[i].fork, "DESTROY");
	}

	safe_mutex(&table->log_mutex, "DESTROY");
	safe_mutex(&table->table_mutex, "DESTROY");

	free(table->philo);
	free(table->forks);
	return (NULL);
}
