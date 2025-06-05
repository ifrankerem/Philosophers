/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:22:44 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/06 01:24:39 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	logging(t_philo *philo, char *action)
{
	long	elapsed;

	if (philo->hunger_status == true) //? thread safe?
		return ;
	elapsed = current_time("MILLISECOND") - philo->table->time_for_sim_start;
	safe_mutex(&philo->table->log_mutex, "LOCK");
	if (ft_strcmp(action, "TAKEFORK") == 0)
		printf("%ld %d has taken a fork", elapsed, philo->philo_id);
	if (ft_strcmp(action, "EATING") == 0)
		printf("%ld %d is eating", elapsed, philo->philo_id);
	if (ft_strcmp(action, "SLEEPING") == 0)
		printf("%ld %d is sleeping", elapsed, philo->philo_id);
	if (ft_strcmp(action, "DIE") == 0)
		printf("%ld %d died", elapsed, philo->philo_id);
	safe_mutex(&philo->table->log_mutex, "UNLOCK");
}
