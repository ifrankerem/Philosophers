/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:04:58 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/05 15:45:04 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
void	set_long(pthread_mutex_t *mutex, long *target, long value)
{
	safe_mutex(mutex, "LOCK");
	*target = value;
	safe_mutex(mutex, "UNLOCK");
}

void	set_bool(pthread_mutex_t *mutex, bool *target, bool value)
{
	safe_mutex(mutex, "LOCK");
	*target = value;
	safe_mutex(mutex, "UNLOCK");
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	return_value;

	safe_mutex(mutex, "LOCK");
	return_value = *value;
	safe_mutex(mutex, "UNLOCK");
	return (return_value);
}

bool	get_bool(pthread_mutex_t *mutex,bool *value)
{
	bool	return_value;

	safe_mutex(mutex, "LOCK");
	return_value = *value;
	safe_mutex(mutex, "UNLOCK");
	return (return_value);
}
