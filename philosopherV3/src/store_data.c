
#include "../philo.h"

void store_data(int argc, char **argv, t_main_philo *philo)
{
	int i = 1;

	philo->counter_eat = 0;
	if(argc == 5)
		philo->counter_eat = -1;
	while(argv[i])
	{
		if(i == 1)
			philo->nb_philo = ft_atoi(argv[i]);
		if(i == 2)
			philo->t_die = ft_atoi(argv[i]);
		if(i == 3)
			philo->t_eat = ft_atoi(argv[i]);
		if(i == 4)
			philo->t_sleep = ft_atoi(argv[i]);
		if(i == 5)
			philo->counter_eat = ft_atoi(argv[i]);
		i++;
	}
	philo->mtx_philo = 0;
	//printf("%d\n", philo->nb_philo);
	//printf("%d\n", philo->t_die);
	//printf("%d\n", philo->t_eat);
	//printf("%d\n", philo->t_sleep);
	//printf("%d\n", philo->counter_eat);
}
