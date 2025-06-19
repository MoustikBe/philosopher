/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:58:28 by misaac-c          #+#    #+#             */
/*   Updated: 2024/06/25 19:59:29 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	store_data(int argc, char **argv, t_main_philo *philo)
{
	int	i;

	i = 1;
	philo->counter_eat = 0;
	if (argc == 5)
		philo->counter_eat = -1;
	while (argv[i])
	{
		if (i == 1)
			philo->nb_philo = ft_atoi(argv[i]);
		if (i == 2)
			philo->t_die = ft_atoi(argv[i]);
		if (i == 3)
			philo->t_eat = ft_atoi(argv[i]);
		if (i == 4)
			philo->t_sleep = ft_atoi(argv[i]);
		if (i == 5)
			philo->counter_eat = ft_atoi(argv[i]);
		i++;
	}
	if (philo->nb_philo == 0)
		return (1);
	philo->mtx_philo = 0;
	return (0);
}
