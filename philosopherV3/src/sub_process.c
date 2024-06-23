#include "../philo.h"


void    wait_thread(t_main_philo *philo_main)
{
    while(1)
    {
        pthread_mutex_lock(&philo_main->wait_mtx);
        if(philo_main->mtx_philo == philo_main->nb_philo)
        {
            pthread_mutex_unlock(&philo_main->wait_mtx);
            break ;
        }
        pthread_mutex_unlock(&philo_main->wait_mtx);
    }
}

void    thread_utils_init(t_main_philo *philo_main, int id_thread)
{
    struct timeval start_time;
    pthread_mutex_init(&philo_main->philo[id_thread].fork, NULL);
    pthread_mutex_init(&philo_main->locker, NULL);
    gettimeofday (&start_time, NULL);
    philo_main->start_time = start_time.tv_sec;
    philo_main->start_time_usec = start_time.tv_usec;
    if(id_thread % 2 == 0)
        ft_usleep(5, philo_main);
    if(philo_main->nb_philo % 2 != 0 && id_thread == 0)
        ft_usleep(philo_main->t_eat + 1, philo_main);
}

void eat_exec(t_main_philo *philo_main, int id_thread, int second_val)
{
    struct timeval last_meal;
    
    gettimeofday (&last_meal, NULL);
    pthread_mutex_lock(&philo_main->food_mtx);
    philo_main->philo[id_thread].last_meal = last_meal.tv_sec;
    philo_main->philo[id_thread].last_meal_usec = last_meal.tv_usec;
    pthread_mutex_unlock(&philo_main->food_mtx);
    eat_process(philo_main, philo_main->philo[id_thread]);
    pthread_mutex_unlock(&philo_main->philo[second_val].fork);
    pthread_mutex_unlock(&philo_main->philo[id_thread].fork);
}

int init_second_val(t_main_philo *philo_main, int id_thread)
{
    int second_val;

    second_val = 0;
    if(id_thread == 0)
        second_val = philo_main->nb_philo - 1;
    else
        second_val = id_thread - 1;
    return(second_val);
}


