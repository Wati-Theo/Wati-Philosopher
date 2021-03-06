/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:27:09 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/28 18:06:06 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Wati-Includes/Wati_Philosopher.h"

void	snitching(t_philo *philo, int choice)
{
	pthread_mutex_lock(&philo->data->is_snitching);
	if (choice == 1)
		printf("%d %d is thinking\n",
			get_time_difference(philo->data->start_time), philo->id);
	else if (choice == 2)
		printf("%d %d has taken a fork\n",
			get_time_difference(philo->data->start_time), philo->id);
	else if (choice == 3)
		printf("%d %d is eating\n",
			get_time_difference(philo->data->start_time), philo->id);
	else if (choice == 4)
		printf("%d %d is sleeping\n",
			get_time_difference(philo->data->start_time), philo->id);
	else if (choice == 5)
		printf("%d %d died\n",
			get_time_difference(philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->is_snitching);
}

void	*sleep_philo(t_philo *philo)
{
	snitching(philo, 4);
	wati_usleep(philo->data, philo->data->time_to_sleep);
	return (think_philo(philo));
}

void	*eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	snitching(philo, 2);
	if (philo->id == 1)
		pthread_mutex_lock(&philo->data->forks[philo->data->nb_philo - 1]);
	else
		pthread_mutex_lock(&philo->data->forks[philo->id - 2]);
	snitching(philo, 2);
	pthread_mutex_lock(&philo->data->last_meal_security);
	philo->last_meal = get_time_difference(philo->data->start_time);
	pthread_mutex_unlock(&philo->data->last_meal_security);
	snitching(philo, EAT);
	wati_usleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	if (philo->id == 1)
		pthread_mutex_unlock(&philo->data->forks[philo->data->nb_philo - 1]);
	else
		pthread_mutex_unlock(&philo->data->forks[philo->id - 2]);
	pthread_mutex_lock(&philo->data->eat_check);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->data->eat_check);
	return (sleep_philo(philo));
}

void	*think_philo(void *arg)
{
	t_philo		*philo;

	philo = arg;
	snitching(philo, 1);
	if (!(philo->id % 2) && get_time_difference(philo->data->start_time)
		< (unsigned int)(philo->data->time_to_sleep + philo->data->time_to_eat))
	{
		wati_usleep(philo->data, 88);
	}
	return (eat_philo(philo));
}
