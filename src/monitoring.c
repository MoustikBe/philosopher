/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:21:30 by misaac-c          #+#    #+#             */
/*   Updated: 2024/06/25 19:54:18 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	print_long_line(struct timeval actual_time,
							t_main_philo *philo_main, t_philo *philo, int i)
{
	printf ("%ld %d died\n", ((actual_time.tv_sec * 1000
				+ actual_time.tv_usec / 1000) - (philo_main->start_time
				* 1000 + philo_main->start_time_usec / 1000) + 1),
		philo[i].id_philo);
}

void	monitoring_function(t_main_philo *philo_main, t_philo *p)
{
	struct timeval	actual_time;
	int				result;
	int				i;

	while (1 && philo_main->end_flag != 1)
	{
		i = 0;
		while (i != philo_main->nb_philo && philo_main->end_flag != 1)
		{
			gettimeofday (&actual_time, NULL);
			pthread_mutex_lock(&philo_main->food_mtx);
			result = ((actual_time.tv_sec * 1000 + actual_time.tv_usec / 1000)
					- (p[i].last_meal * 1000 + p[i].last_meal_usec / 1000));
			if (result >= philo_main->t_die - 1 && result)
			{
				pthread_mutex_unlock(&philo_main->food_mtx);
				print_long_line(actual_time, philo_main, p, i);
				philo_main->is_dead = 1;
				philo_main->end_flag = 1;
				break ;
			}
			pthread_mutex_unlock(&philo_main->food_mtx);
			i++;
		}
	}
}
