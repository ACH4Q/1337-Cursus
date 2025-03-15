
#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>


typedef pthread_mutex_t	t_mutex;

typedef struct s_fork
{
	t_mutex				fork;
	int					id;
	struct s_fork		*next;
}						t_fork;

typedef struct s_box
{
	long				number_of_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				number_looping;
	int					someone_die;
	t_mutex				mutex_die;
	t_mutex				write;
	t_mutex				mutex_stop;
	t_fork				*fork;
	long				start;
	long				stop;
	t_mutex				check_stop;
	t_mutex				check_last;
}						t_box;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	t_box				*box;
	long				last_eat;
	t_fork				*l_fork;
	t_fork				*r_fork;
}						t_philo;


void					creat_philo(char **av);
int						ft_strlen(char *s);
int						not_number(char *s);
int						check_arg(char **av);
void					run_philo(char **av);
long					ft_atoi(char *s);
void					*thread_philo(void *arg);
void					*ft_calloc(size_t nelem, size_t elsize);
void					creat_one_philo(char **av);
void					launch_philo(t_box *box, t_philo *thread);
void					wait_philo(t_box *box, t_philo *thread);
void					free_all(t_box *box, t_philo *thread);
int						for25line(t_box *box);
int						check(t_box *box);
void					unlock(t_mutex *ptr);
void					ft_lock(t_mutex *ptr);
void					mutex_init(t_mutex *ptr);
long					get_time(void);
void					ft_sleep(t_philo *pth, long end);
void					ft_sleep_for_one(long end);
#endif
