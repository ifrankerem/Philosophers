/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:22:44 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/10 23:04:20 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	logging(t_philo *philo, char *action)
{
	long	elapsed;

	if (get_bool(&philo->table->table_mutex,
			&philo->table->is_dinner_end) == true && ft_strcmp(action,
			"DIE") != 0)
		return ;
	if (get_bool(&philo->philo_mutex, &philo->hunger_status) == true)
		//? thread safe?
		return ;
	elapsed = current_time("MILLISECOND") - philo->table->time_for_sim_start;
	safe_mutex(&philo->table->log_mutex, "LOCK");
	if (ft_strcmp(action, "TAKEFORK") == 0)
		printf("%ld %ld has taken a fork\n", elapsed, philo->philo_id);
	if (ft_strcmp(action, "EATING") == 0)
		printf("%ld %ld is eating\n", elapsed, philo->philo_id);
	if (ft_strcmp(action, "SLEEPING") == 0)
		printf("%ld %ld is sleeping\n", elapsed, philo->philo_id);
	if (ft_strcmp(action, "THINKING") == 0)
		printf("%ld %ld is thinking\n", elapsed, philo->philo_id);
	if (ft_strcmp(action, "DIE") == 0)
		printf("%ld %ld died\n", elapsed, philo->philo_id);
	safe_mutex(&philo->table->log_mutex, "UNLOCK");
}
