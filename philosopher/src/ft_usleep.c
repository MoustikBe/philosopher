/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:38:30 by misaac-c          #+#    #+#             */
/*   Updated: 2024/06/23 23:03:29 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("ERROR, fail get_time_of_day");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t millisecond, t_main_philo *philo_main)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < millisecond && philo_main->is_dead != 1)
		usleep(50);
	return ;
}
