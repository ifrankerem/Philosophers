/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:04:58 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/02 22:12:30 by iarslan          ###   ########.fr       */
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
void	set_long(t_table *table, long *target, long value)
{
	safe_mutex(&table->table_mutex, "LOCK");
	*target = value;
	safe_mutex(&table->table_mutex, "UNLOCK");
}

void	set_bool(t_table *table, bool *target, bool value)
{
	safe_mutex(&table->table_mutex, "LOCK");
	*target = value;
	safe_mutex(&table->table_mutex, "UNLOCK");
}

long	get_long(t_table *table, long *value)
{
	long	return_value;

	safe_mutex(&table->table_mutex, "LOCK");
	return_value = *value;
	safe_mutex(&table->table_mutex, "UNLOCK");
	return (return_value);
}

bool	get_bool(t_table *table, bool *value)
{
	bool	return_value;

	safe_mutex(&table->table_mutex, "LOCK");
	return_value = *value;
	safe_mutex(&table->table_mutex, "UNLOCK");
	return (return_value);
}
