
#include "header.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

long	ft_atoi(char *s)
{
	long	res;
	int		i;

	i = 0;
	res = 0;
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		res = (res * 10) + s[i] - '0';
		if (res > 2147483647)
			return (21474836479);
		i++;
	}
	if (!res)
		return (21474836479);
	return (res);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	if (nelem == 0 || elsize == 0)
	{
		nelem = 1;
		elsize = 1;
	}
	ptr = malloc(nelem * elsize);
	if (ptr)
		memset(ptr, 0, nelem * elsize);
	return (ptr);
}
