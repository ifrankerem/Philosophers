/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:30:18 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/06 02:15:11 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	safe_mutex(pthread_mutex_t *mutex, char *flag)
{
	if (!ft_strcmp(flag, "INIT"))
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return (ft_error_int("Mutex Failed!"));
	}
	else if (!ft_strcmp(flag, "DESTROY"))
	{
		if (pthread_mutex_destroy(mutex) != 0)
			return (ft_error_int("Mutex Failed!"));
	}
	else if (!ft_strcmp(flag, "LOCK"))
	{
		if (pthread_mutex_lock(mutex) != 0)
			return (ft_error_int("Mutex Failed!"));
	}
	else if (!ft_strcmp(flag, "UNLOCK"))
	{
		if (pthread_mutex_unlock(mutex) != 0)
			return (ft_error_int("Mutex Failed!"));
	}
	return (0);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (ft_error_ptr("Malloc Error!"));
	return (ptr);
}

int	safe_thread_op(pthread_t *th, void *(*func)(void *), char *flag)
{
	if (!ft_strcmp(flag, "CREATE"))
	{
		if (pthread_create(th, NULL, func, NULL) != 0)
			return (ft_error_int("Thread is Failed!"));
	}
	else if (!ft_strcmp(flag, "JOIN"))
	{
		if (pthread_join(*th, NULL) != 0)
			return (ft_error_int("Thread is Failed!"));
	}
	return (0);
}
void	safe_increase_long(pthread_mutex_t *mutex, long *target)
{
	pthread_mutex_lock(mutex);
	(*target)++;
	pthread_mutex_unlock(mutex);
}
