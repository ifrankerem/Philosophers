/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:04:58 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/12 09:52:41 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_increase_long(pthread_mutex_t *mutex, long *target)
{
	pthread_mutex_lock(mutex);
	(*target)++;
	pthread_mutex_unlock(mutex);
}

void	set_long(pthread_mutex_t *mutex, long *target, long value)
{
	pthread_mutex_lock(mutex);
	*target = value;
	pthread_mutex_unlock(mutex);
}

void	set_bool(pthread_mutex_t *mutex, bool *target, bool value)
{
	pthread_mutex_lock(mutex);
	*target = value;
	pthread_mutex_unlock(mutex);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	return_value;

	pthread_mutex_lock(mutex);
	return_value = *value;
	pthread_mutex_unlock(mutex);
	return (return_value);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	return_value;

	pthread_mutex_lock(mutex);
	return_value = *value;
	pthread_mutex_unlock(mutex);
	return (return_value);
}
