/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:19:50 by misaac-c          #+#    #+#             */
/*   Updated: 2024/06/23 22:35:24 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_main_philo	*philo_main;
	t_philo			*philo;	

	if (argc < 5 || argc > 6)
		return (printf("ERROR, BAD NUMBER OF ARGUMENTS\n"));
	if (parsing(argv))
		return (2);
	philo_main = malloc(sizeof(t_main_philo));
	philo = malloc(sizeof(t_philo));
	if (!philo || !philo_main)
		return (printf("ERROR, malloc\n"));
	store_data(argc, argv, philo_main);
	thread_creator(philo_main, philo);
	free(philo);
	free(philo_main);
	return (0);
}
