#ifndef	PHILO_H
#define PHILO_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <sys/time.h>
#include <pthread.h> 

typedef pthread_mutex_t t_mtx;

typedef struct t_philo
{
	int             nb_philo;
	int             mtx_philo;
	int             id_philo;
	t_mtx            fork;
    pthread_t       philo;
	unsigned long   last_meal;
    unsigned long   last_meal_usec;
}	t_philo;

typedef struct t_main_philo
{
	unsigned long start_time;
    unsigned long start_time_usec;
    int is_dead;
	int end_flag;
	int mtx_philo;
	int	nb_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int counter_eat;
    t_mtx wait_mtx;
    t_mtx food_mtx;
	t_mtx locker;
	t_mtx *wait_philo;
	t_philo	*philo;
}	t_main_philo;


int		ft_atoi(const char *str);
int		ft_isdigit(int dig);
int		parsing(char **argv);
int		init_second_val(t_main_philo *philo_main, int id_thread);
void	store_data(int argc, char **argv, t_main_philo *philo);
void    thread_creator(t_main_philo *philo_main, t_philo *philo);
void	ft_usleep(size_t millisecond, t_main_philo *philo_main);
void	monitoring_function(t_main_philo *philo_main, t_philo *philo);
void    wait_thread(t_main_philo *philo_main);
void    thread_utils_init(t_main_philo *philo_main, int id_thread);
void    exec_routine(t_main_philo *philo_main, int id_thread);
void	eat_process(t_main_philo *philo_main, t_philo philo);
void	eat_exec(t_main_philo *philo_main, int id_thread, int second_val);
void	sleep_process(t_main_philo *philo_main, t_philo philo);
void	think_process(t_main_philo *philo_main, struct timeval last_time, int id_thread);
void	*routine(void *arg);

#endif