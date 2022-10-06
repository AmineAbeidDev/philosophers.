/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:54:06 by aabeid            #+#    #+#             */
/*   Updated: 2022/06/09 11:07:31 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKER_H
# define LINKER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct t_status
{
	struct t_status	*next;
	pthread_mutex_t	lfork;
	pthread_mutex_t	rfork;
	int				rf;
	int				lf;
	int				idx;
	int				must_eat;
	int				last_meal;
	int				is_eating;
	struct t_status	*prev;
}	t_status;

typedef struct t_vars
{
	struct t_status	*status;
	int				clock;
	long long		start_time;
	int				time_to_die;
	int				time_to_eat;
	int				their_number;
	int				time_to_sleep;
	pthread_mutex_t	print;
}	t_vars;

long long int	get_time(void);
void			ft_usleep(int waiting);
int				ft_atoi(const char *str);
int				ft_lstsize(t_status *lst);
t_status		*ft_lstlast(t_status *lst);
void			mutex_destroyer(t_vars *p);
t_status		*ft_lstnew(int idx, int must_eat);
void			eating(t_vars *p, t_status *status);
void			philosophers_creator(t_vars *philo);
int				death_clock(t_vars *p, t_status *status);
int				input_checker(char **args, int args_sum);
void			ft_lstadd_back(t_status **lst, t_status *new);
void			forks_on(t_vars *p, t_status *is_eating, int on);
void			printer(int clock, int idx, char *msg, t_vars *p);
void			sleeping_and_thinking(t_vars *p, t_status *status);

#endif
