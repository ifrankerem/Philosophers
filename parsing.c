/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:43:27 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/06 02:35:35 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(int c)
{
	return ((c <= '9' && c >= '0'));
}
static int	is_space(int c)
{
	return ((c <= 13 && c >= 9) || (c == 32));
}
static const char	*valid(char *av)
{
	const char	*number;

	while (is_space(*av))
		av++;
	if (*av == '-')
		return (ft_error_str("Arguments cannot be negative!"), NULL);
	else if (*av == '+')
		av++;
	if (is_digit(*av) != 1)
		return (ft_error_str("Arguments need to be a number!"), NULL);
	number = av;
	return (number);
}

static long	ft_atol(char *av)
{
	int		i;
	long	number;

	number = 0;
	i = -1;
	while (is_digit(av[++i]))
		number = (number * 10) + (av[i] - '0');
	if (number > INT_MAX)
		return (ft_error_long("Argument value is higher than INT_MAX value!"));
	return (number);
}

void	parsing(t_table *table, char **av)
{
	table->philo_nbr = ft_atol(valid(av[0]));
	table->time_to_die = ft_atol(valid(av[1])) * 1000;
	//* usleep fonksiyonu mikrosaniye alıyo 1 milisaniye = 1000 mikrosaniye
	table->time_to_eat = ft_atol(valid(av[2])) * 1000;
	table->time_to_sleep = ft_atol(valid(av[3])) * 1000;
	if (table->time_to_die || table->time_to_eat
		|| table->time_to_sleep < 60000)
		return (ft_error_ptr("Please enter values more than 60ms"));
	if (av[4] != NULL)
		table->number_of_limit_meals = ft_atol(valid(av[4]));
	else
		table->number_of_limit_meals = -1;
	//! sondaki optional argüman var mı flagi
}
