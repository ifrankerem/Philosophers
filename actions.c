/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:30:16 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/09 20:10:13 by iarslan          ###   ########.fr       */
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
void	eat(t_philo *philo)
{
	take_forks(philo);
	philo->meals_eaten++;
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		current_time("MILLISECOND"));
	logging(philo, "EATING");
	better_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->number_of_limit_meals > 0
		&& philo->meals_eaten == philo->table->number_of_limit_meals)
		set_bool(&philo->philo_mutex, &philo->hunger_status, true);
	// monitor tarafından okunacagı için thread safe!
	safe_mutex(&philo->right_fork->fork, "UNLOCK");
	safe_mutex(&philo->left_fork->fork, "UNLOCK");
}

void	sleeping(t_philo *philo)
{
	logging(philo, "SLEEPING");
	better_usleep(philo->table->time_to_sleep, philo->table);
}

void	thinking(t_philo *philo)
{
	logging(philo, "THINKING");
}
