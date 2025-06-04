/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:22:44 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/04 15:45:43 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	logging(t_philo *philo, char *action)
{
	safe_mutex(&philo->table->log_mutex,"LOCK");
	if (ft_strcmp(action, "TAKEFORK") == 0)
		printf("%ld %d has taken a fork", current_time("MILISECOND"),
			philo->philo_id);
	if (ft_strcmp(action, "EATING") == 0)
		printf("%ld %d is eating", current_time("MILISECOND"), philo->philo_id);
	if (ft_strcmp(action, "SLEEPING") == 0)
		printf("%ld %d is sleeping", current_time("MILISECOND"),
			philo->philo_id);
	if (ft_strcmp(action, "DIE") == 0)
		printf("%ld %d died", current_time("MILISECOND"), philo->philo_id);
	safe_mutex(&philo->table->log_mutex,"UNLOCK");
}
