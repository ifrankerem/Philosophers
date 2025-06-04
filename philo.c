/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:30:16 by iarslan           #+#    #+#             */
/*   Updated: 2025/06/04 17:43:46 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
burda log bastırcaz
filozofa ait structtaki şeyleri arttırıp azaltıcaz(bunu mutexle mi yapıcaz yoksa her thread zaten kendisi yapıyo mutex lock unlocka gerek var mı ?)
usleep basıcaz bize arguman verilen süre kadar
*/

void	take_forks(t_philo *philo)
{
	if (philo->philo_id % 2)
	{
        safe_mutex(&philo->table->forks->)
	}
	else
}
void	eat(t_philo *philo)
{
	safe_mutex(&philo->table->meal_mutex, "LOCK");
	philo->meals_eaten++;
	philo->status = true;
	safe_mutex(&philo->table->meal_mutex, "UNLOCK");
	logging(philo, "EATING");
	better_usleep(philo->table->time_to_eat, philo->table);
}

void	sleeping(t_philo *philo)
{
	better_usleep(philo->table->time_to_sleep, philo->table);
	logging(philo, "SLEEPING");
}

void	thinking(t_philo *philo)
{
	logging(philo, "THINKING");
}
