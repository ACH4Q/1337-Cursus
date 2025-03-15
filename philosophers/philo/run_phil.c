
#include "header.h"

void	run_philo(char **av)
{
	if (check_arg(av))
		return ;
	if (ft_atoi(av[1]) == 1)
		creat_one_philo(av);
	else
		creat_philo(av);
}
