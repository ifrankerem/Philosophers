/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:43:27 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/11 12:07:40 by iarslan          ###   ########.fr       */
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

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		return (ft_error_int("Wrong number of arguments!"));
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (is_space(argv[i][j]))
				j++;
			if (argv[i][j] == '+')
				j++;
			if (!is_digit(argv[i][j]))
				return (ft_error_int("Invalid character in argument!"));
			while (is_digit(argv[i][j]))
				j++;
			if (argv[i][j] && !is_space(argv[i][j]))
				return (ft_error_int("Invalid format!"));
		}
		i++;
	}
	return (0);
}

long	ft_atol(char *arg)
{
	long	num;
	int		i;

	num = 0;
	i = -1;
	while (arg[++i])
	{
		if (!is_digit(arg[i]))
			return (ft_error_long("Non-digit character in argument!"));
		num = num * 10 + (arg[i] - '0');
		if (num > INT_MAX)
			return (ft_error_long("Argument exceeds INT_MAX"));
	}
	return (num);
}

int	parsing(t_table *table, char **av)
{
	table->philo_nbr = ft_atol(av[0]);
	if (table->philo_nbr == -1)
		return (1);
	table->time_to_die = ft_atol(av[1]) * 1000;
	table->time_to_eat = ft_atol(av[2]) * 1000;
	table->time_to_sleep = ft_atol(av[3]) * 1000;
	if (table->time_to_die < 60000 || table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		return (ft_error_int("Please enter values more than 60ms"));
	if (av[4])
		table->number_of_limit_meals = ft_atol(av[4]);
	else
		table->number_of_limit_meals = -1;
	return (0);
}
