/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mngr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:05:17 by misaac-c          #+#    #+#             */
/*   Updated: 2024/06/25 20:08:32 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	store_data_philo(t_main_philo *philo_main, t_philo *philo, int i)
{
	struct timeval	last_meal;

	gettimeofday(&last_meal, NULL);
	pthread_mutex_lock(&philo_main->food_mtx);
	philo[i].last_meal = last_meal.tv_sec;
	philo[i].last_meal_usec = last_meal.tv_usec;
	pthread_mutex_unlock(&philo_main->food_mtx);
	philo[i].id_philo = i + 1;
}

void	join_all_thread(t_main_philo *philo_main, t_philo *philo)
{
	int	i;

	i = 0;
	while (i != philo_main->nb_philo)
	{
		pthread_join(philo[i].philo, NULL);
		i++;
	}
}

void	thread_creator(t_main_philo *philo_main, t_philo *philo)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * philo_main->nb_philo + 1);
	philo_main->philo = philo;
	pthread_mutex_init(&philo_main->wait_mtx, NULL);
	pthread_mutex_init(&philo_main->food_mtx, NULL);
	while (i != philo_main->nb_philo)
	{
		if (pthread_create(&philo[i].philo, NULL, &routine, philo_main))
		{
			printf("ERROR, thread creation fail\n");
			return ;
		}
		store_data_philo(philo_main, philo, i);
		i++;
	}
	monitoring_function(philo_main, philo);
	join_all_thread(philo_main, philo);
	pthread_mutex_destroy(&philo_main->wait_mtx);
	pthread_mutex_destroy(&philo_main->food_mtx);
	free(philo);
}
