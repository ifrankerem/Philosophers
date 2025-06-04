/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:30:22 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/04 15:37:49 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table table;
	if (ac == 5 || ac == 6)
		parsing(&table, av + 1);
	else
		return (ft_error_int("Wrong Argument Number!"));

	data_init(&table);

	// baslangıc zamanını da alcıaksın
	current_time();
	dinner();
	// clean everything clean();
	else return (-1);
}