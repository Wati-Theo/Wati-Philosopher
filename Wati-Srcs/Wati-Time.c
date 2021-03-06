/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:59:41 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/28 18:09:24 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Wati-Includes/Wati_Philosopher.h"

void	wati_usleep(t_data *data, unsigned int sleep_time)
{
	struct timeval	s_start_time;
	int				sleep;

	sleep = data->nb_philo * 0.5;
	gettimeofday(&s_start_time, NULL);
	while (sleep_time > get_time_difference(s_start_time))
		usleep(60);
}

unsigned int	get_time_difference(struct timeval old_time)
{
	struct timeval	s_current_time;
	unsigned int	time_current;
	unsigned int	time_old;

	gettimeofday(&s_current_time, NULL);
	time_current = s_current_time.tv_sec * (unsigned int)1000
		+ s_current_time.tv_usec / 1000;
	time_old = old_time.tv_sec * (unsigned int)1000 + old_time.tv_usec / 1000;
	return (time_current - time_old);
}
