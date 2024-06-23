/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:39:05 by misaac-c          #+#    #+#             */
/*   Updated: 2024/06/23 23:06:53 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_process(t_main_philo *philo_main, t_philo philo)
{
	struct timeval time_eat;
	gettimeofday (&time_eat, NULL);

    if(philo_main->is_dead == 1)
        return ;
	else
	{
		printf("%ld %d is eating\n", ((time_eat.tv_sec * 1000 + time_eat.tv_usec / 1000) - (philo_main->start_time * 1000 + philo_main->start_time_usec / 1000)), philo.id_philo);
		ft_usleep(philo_main->t_eat, philo_main);
	}
}

void	sleep_process(t_main_philo *philo_main, t_philo philo)
{
	struct timeval time_sleep;
	
	gettimeofday (&time_sleep, NULL);
	if(philo_main->is_dead == 1)
		return ;
	printf("%ld %d is sleeping\n", ((time_sleep.tv_sec * 1000 + time_sleep.tv_usec / 1000) - (philo_main->start_time * 1000 + philo_main->start_time_usec / 1000)), philo.id_philo);
	ft_usleep(philo_main->t_sleep, philo_main);
}

void think_process(t_main_philo *philo_main, struct timeval last_time, int id_thread)
{
    int result;
	
	result = ((philo_main->t_die - philo_main->t_sleep - philo_main->t_eat) / 2);
	gettimeofday (&last_time, NULL);
	printf("%ld %d is thinking\n", ((last_time.tv_sec * 1000 + last_time.tv_usec / 1000) - (philo_main->start_time * 1000 + philo_main->start_time_usec / 1000)), philo_main->philo[id_thread].id_philo);
    if(result > 50)
        ft_usleep(result, philo_main);
}

void*   routine(void *arg)
{
	t_main_philo *philo_main = (t_main_philo *)arg;
	pthread_mutex_lock(&philo_main->wait_mtx);
	int id_thread = philo_main->mtx_philo;
	philo_main->mtx_philo++;
	pthread_mutex_unlock(&philo_main->wait_mtx);
	wait_thread(philo_main);
	thread_utils_init(philo_main, id_thread);
	exec_routine(philo_main, id_thread);
	philo_main->end_flag = 1;
    pthread_mutex_destroy(&philo_main->philo[id_thread].fork);
	pthread_mutex_destroy(&philo_main->locker);
	return NULL;
}

void exec_routine(t_main_philo *philo_main, int id_thread)
{
	struct timeval last_time;
	int nb_meal = 0;
    int second_val;
	
	while(nb_meal != philo_main->counter_eat)
	{
        second_val = init_second_val(philo_main, id_thread);
        pthread_mutex_lock(&philo_main->philo[second_val].fork); // BLOQUE TANT QUE IL N'Y A PAS DE UNLOCK
        gettimeofday (&last_time, NULL);
		if(philo_main->is_dead == 1)
			break ;
        printf("%ld %d has taken a fork\n", ((last_time.tv_sec * 1000 + last_time.tv_usec / 1000) - (philo_main->start_time * 1000 + philo_main->start_time_usec / 1000)), id_thread + 1);
        pthread_mutex_lock(&philo_main->philo[id_thread].fork);
        gettimeofday (&last_time, NULL);
		if(philo_main->is_dead == 1)
			break ;
        printf("%ld %d has taken a fork\n", ((last_time.tv_sec * 1000 + last_time.tv_usec / 1000) - (philo_main->start_time * 1000 + philo_main->start_time_usec / 1000)), id_thread + 1);
		eat_exec(philo_main, id_thread, second_val);
        if(philo_main->is_dead == 1)
            break ;
        nb_meal++;
		sleep_process(philo_main, philo_main->philo[id_thread]);
        if(philo_main->is_dead == 1)
            break ;
		think_process(philo_main, last_time, id_thread);
    }
}
