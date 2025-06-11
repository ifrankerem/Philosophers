/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:43:27 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/11 02:27:16 by iarslan          ###   ########.fr       */
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
long	safe_atol(char *arg)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (*arg && is_space(*arg))
		arg++;
	if (*arg == '-')
		return (ft_error_long("Argument cannot be negative!"));
	if (*arg == '+')
		arg++;
	if (!is_digit(*arg))
		return (ft_error_long("Argument must be numeric!"));
	while (arg[i])
	{
		if (!is_digit(arg[i]))
			return (ft_error_long("Non-digit character in argument!"));
		num = num * 10 + (arg[i] - '0');
		if (num > INT_MAX)
			return (ft_error_long("Argument exceeds INT_MAX"));
		i++;
	}
	return (num);
}

int	parsing(t_table *table, char **av)
{
	if (av[0])
		table->philo_nbr = safe_atol(av[0]);
	if (av[1])
		table->time_to_die = safe_atol(av[1]) * 1000;
	if (av[2])
		table->time_to_eat = safe_atol(av[2]) * 1000;
	if (av[3])
		table->time_to_sleep = safe_atol(av[3]) * 1000;
	if (table->time_to_die < 60000 || table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		return (ft_error_int("Please enter values more than 60ms"));
	if (av[4])
		table->number_of_limit_meals = safe_atol(av[4]);
	else
		table->number_of_limit_meals = -1;
	return (0);
}
