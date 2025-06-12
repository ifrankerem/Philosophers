/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:22:44 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/12 06:58:52 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	logging(t_philo *philo, t_log_unit action_code)
{
	long	elapsed;

	if (get_bool(&philo->table->table_mutex,
			&philo->table->is_dinner_end) == true && action_code != DIE)
		return ;
	elapsed = current_time(MILLISECOND) - philo->table->time_for_sim_start;
	pthread_mutex_lock(&philo->table->log_mutex);
	if (action_code == TAKEFORK)
		printf("%ld %ld has taken a fork\n", elapsed, philo->philo_id);
	else if (action_code == EATING)
		printf("%ld %ld is eating\n", elapsed, philo->philo_id);
	else if (action_code == SLEEPING)
		printf("%ld %ld is sleeping\n", elapsed, philo->philo_id);
	else if (action_code == THINKING)
		printf("%ld %ld is thinking\n", elapsed, philo->philo_id);
	else if (action_code == DIE)
		printf("%ld %ld died\n", elapsed, philo->philo_id);
	pthread_mutex_unlock(&philo->table->log_mutex);
}
