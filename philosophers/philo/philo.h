/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 15:03:53 by ybakker       #+#    #+#                 */
/*   Updated: 2022/05/06 18:03:47 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct	s_main;

typedef struct s_philosopher
{
	int					x;
	int					x_ate;
	int					left_fork;
	int					right_fork;
	long long			t_last_meal;
	struct s_main		*main;
	pthread_t			thread;
}						t_philosopher;

typedef struct s_main
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat;
	int					dieded;
	int					total_eat;
	int					all_ate;
	long long			first_timestamp;
	int					number_eat;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[200];
	pthread_mutex_t		writing_dead;
	pthread_mutex_t		t_t_d;
	t_philosopher		philosophers[250];
}						t_main;

int			ft_input(t_main *main, char **argv);
int			ft_launch(t_main *main);
int			ft_launch_single(t_main *main);
void		*ft_run_philo(void *void_philosopher);
void		*ft_wait_death(void *void_philosopher);

int			ft_error_message(char *str);
int			ft_error_message_int(char *str, int i);
int			ft_strlen(char const *str);
int			ft_atoi(char const *str);
int			ft_mutex(t_main *main);
int			ft_philo_fill(t_main *main);
long long	ft_time(void);
void		ft_print_philo(t_main *main, int x, char *command);
void		ft_sleep_check(long long time, t_main *main);
int			ft_check_diff(t_philosopher *philo, t_main *main);
int			ft_dead(t_philosopher *philo, t_main *main);

void		ft_eats(t_philosopher *philo);
void		ft_exit(t_main *main, t_philosopher *philos);

#endif
