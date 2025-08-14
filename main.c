/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:30:22 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/12 09:53:52 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (check_args(ac, av) == 1)
		return (1);
	if (parsing(&table, av + 1) == 1)
		return (1);
	if (data_init(&table) == 1)
		return (1);
	if (dinner(&table) == 1)
		return (1);
	if (clean(&table) == 1)
		return (1);
	return (0);
}
