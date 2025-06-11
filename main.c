/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:30:22 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/11 04:21:08 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
		return (ft_error_int("Wrong number of arguments!"));
	if (parsing(&table, av + 1))
		return (1);
	if (data_init(&table))
		return (clean(&table), 1);
	if (dinner(&table))
		return (clean(&table), 1);
	return (0);
}
