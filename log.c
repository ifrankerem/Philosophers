/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:22:44 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/04 00:00:34 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	logging(t_philo *philo, char *action)
{
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
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:22:44 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/03 05:02:02 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	logging(t_philo *philo, char *action)
{
	safe_mutex(&philo->table->log_mutex, "LOCK");
	if (ft_strcmp(action, "TAKEFORK") == 0)
		printf("%ld %d has taken a fork\n", current_time("MILLISECOND"),
			philo->philo_id);
	if (ft_strcmp(action, "EATING") == 0)
		printf("%ld %d is eating\n", current_time("MILLISECOND"),
			philo->philo_id);
	if (ft_strcmp(action, "SLEEPING") == 0)
		printf("%ld %d is sleeping\n", current_time("MILLISECOND"),
			philo->philo_id);
	if (ft_strcmp(action, "DIE") == 0)
		printf("%ld %d died\n", current_time("MILLISECOND"), philo->philo_id);
	safe_mutex(&philo->table->log_mutex, "UNLOCK");
}
