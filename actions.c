/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:30:16 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/11 10:44:56 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
burda log bastırcaz
filozofa ait structtaki şeyleri arttırıp azaltıcaz(bunu mutexle mi yapıcaz yoksa her thread zaten kendisi yapıyo mutex lock unlocka gerek var mı ?)
usleep basıcaz bize arguman verilen süre kadar
*/

static void	take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		safe_mutex(&philo->right_fork->fork, "LOCK");
		logging(philo, "TAKEFORK");
		safe_mutex(&philo->left_fork->fork, "LOCK");
		logging(philo, "TAKEFORK");
	}
	else
	{
		safe_mutex(&philo->left_fork->fork, "LOCK");
		logging(philo, "TAKEFORK");
		safe_mutex(&philo->right_fork->fork, "LOCK");
		logging(philo, "TAKEFORK");
	}
}
bool	eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (get_bool(&philo->philo_mutex, &philo->hunger_status) == true
		|| get_bool(&table->table_mutex, &table->is_dinner_end) == true)
		return (true);
	take_forks(philo);
	safe_increase_long(&philo->philo_mutex, &philo->meals_eaten);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		current_time("MILLISECOND"));
	logging(philo, "EATING");
	better_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->number_of_limit_meals > 0
		&& philo->meals_eaten == philo->table->number_of_limit_meals)
		set_bool(&philo->philo_mutex, &philo->hunger_status, true);
	//! monitor tarafından okunacagı için thread safe! AMA YİNE DE DÜSÜN BK BURAYAA
	safe_mutex(&philo->right_fork->fork, "UNLOCK");
	safe_mutex(&philo->left_fork->fork, "UNLOCK");
	return (false);
}

bool	sleeping(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (get_bool(&philo->philo_mutex, &philo->hunger_status) == true
		|| get_bool(&table->table_mutex, &table->is_dinner_end) == true)
		return (true);
	logging(philo, "SLEEPING");
	better_usleep(philo->table->time_to_sleep, philo->table);
	return (false);
}

bool	thinking(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (get_bool(&philo->philo_mutex, &philo->hunger_status) == true
		|| get_bool(&table->table_mutex, &table->is_dinner_end) == true)
		return (true);
	logging(philo, "THINKING");
	if (philo->table->philo_nbr % 2 == 0 || ((table->time_to_eat * 2)
			- (table->time_to_sleep) < 0))
		return (false);
	better_usleep((table->time_to_eat * 2) - (table->time_to_sleep) * 0.60,
		table);
	return (false);
}
