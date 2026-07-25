#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
#include <sys/time.h>
#include <limits.h>

typedef struct s_rules t_rules;

typedef struct s_philo
{
    int id;
    pthread_t thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    int nb_meal;
    long long last_meal;
    pthread_mutex_t mutex_last_meal;
    t_rules *rules;
}   t_philo ;

typedef struct s_rules
{
    int nb_philo;
    long long start_time;
    long long time_to_die;
    long long time_to_eat;
    long long time_to_sleep;
    long long must_eat;
    pthread_mutex_t *forks;
    pthread_mutex_t mutex_print;
    int stop;
    pthread_mutex_t mutex_stop;
    t_philo *philos;
}   t_rules ;

int    ft_is_nb(char *s);
int    ft_check_arg(int ac, char **av);
int    ft_init_values_rules(t_rules *rules, int ac, char **av);

void    ft_init_values_philo(t_rules *rules);
int ft_error_message(void);
int ft_allocations(t_rules *rules);
int ft_init_mutex(t_rules *rules);
void	ft_free_allocations(t_rules *rules);
void ft_destroy_forks(t_rules *rules, int i);
void ft_destroy_last_meal(t_rules *rules, int i);
long long ft_get_time(void);
long long	ft_atoll(const	char *str);
void	*ft_routine(void *arg);
int ft_start_simulation(t_rules *rules);
int     ft_verif_stop(t_rules *rules);
void    ft_time_to_eat(t_philo *philo);
void    ft_message_died(t_philo *philo);
void    ft_message_think(t_philo *philo);
void    ft_message_sleep(t_philo *philo);
void    ft_message_eat(t_philo *philo);
void    ft_message_fork(t_philo *philo);

#endif