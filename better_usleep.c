/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:21:54 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/12 07:09:36 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(t_time_unit time_code)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (time_code == MILLISECOND)
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	if (time_code == MICROSECOND)
		return (tv.tv_sec * 1000000 + tv.tv_usec);
	return (ft_error_long("Error in gettimeofday function"));
}

void	better_usleep(long waited_time, t_table *table)
{
	long	start;
	long	elapsed;
	long	remaining_time;

	start = current_time(MICROSECOND);
	while (current_time(MICROSECOND) - start < waited_time)
	{
		if (get_bool(&table->table_mutex, &table->is_dinner_end) == true)
			break ;
		elapsed = current_time(MICROSECOND) - start;
		remaining_time = waited_time - elapsed;
		if (remaining_time > 100)
			usleep(100);
		else
		{
			while (current_time(MICROSECOND) - start < waited_time)
				;
			break ;
		}
	}
}
/* bu fonksiyon benim bekleyeceğim süre kadar while da tutup süreyi sürekli
o while içinde süreyi sayıp kontrol edip usleepin sapmasını olabildiğince
en aaza indiriyor!!
*/