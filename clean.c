/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:40:36 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/12 06:55:02 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = table->philo;
	i = -1;
	while (++i < table->philo_nbr)
	{
		if (pthread_mutex_destroy(&philo[i].philo_mutex) != 0)
			return (ft_error_int("Mutex Failed!"));
		if (pthread_mutex_destroy(&table->forks[i].fork) != 0)
			return (ft_error_int("Mutex Failed!"));
	}
	if (pthread_mutex_destroy(&table->log_mutex) != 0)
		return (ft_error_int("Mutex Failed!"));
	if (pthread_mutex_destroy(&table->table_mutex) != 0)
		return (ft_error_int("Mutex Failed!"));
	free(table->philo);
	free(table->forks);
	return (0);
}
