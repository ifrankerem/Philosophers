/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:21:54 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/09 00:18:56 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(char *time_code)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (ft_strcmp(time_code, "SECOND") == 0)
		return (tv.tv_sec + tv.tv_usec / 1000000);
	if (ft_strcmp(time_code, "MILLISECOND") == 0)
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	if (ft_strcmp(time_code, "MICROSECOND") == 0)
		return (tv.tv_sec * 1000000 + tv.tv_usec);
	else
		return (ft_error_long("Error in gettimeofday function"));
	return (-1);
}

void	better_usleep(long waited_time, t_table *table)
{
	long	start;
	long	elapsed;
	long	remaining_time;

	start = current_time("MICROSECOND");
	while (current_time("MICROSECOND") - start < waited_time)
	{
		if (get_bool(&table->table_mutex, &table->is_dinner_end) == true)
			break ;
		elapsed = current_time("MICROSECOND") - start;
		remaining_time = waited_time - elapsed;
		if (remaining_time > 100)
			usleep(remaining_time / 2);
		else
			while (current_time("MICROSECOND") - start < waited_time)
				;
	}
}
/* bu fonksiyon benim bekleyeceğim süre kadar while da tutup süreyi sürekli
o while içinde süreyi sayıp kontrol edip usleepin sapmasını olabildiğince
en aaza indiriyor!!
*/