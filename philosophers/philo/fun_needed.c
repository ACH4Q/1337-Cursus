
#include "header.h"

void	mutex_init(t_mutex *ptr)
{
	pthread_mutex_init(ptr, NULL);
}

void	unlock(t_mutex *ptr)
{
	pthread_mutex_unlock(ptr);
}

void	ft_lock(t_mutex *ptr)
{
	pthread_mutex_lock(ptr);
}
