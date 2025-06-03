#include "asd.h"
#include <sys/types.h>
#include <sys/wait.h>

//? Problem : 2 thread yarat bu threadler gidipte primes dizisini toplamını versin

int				primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	int	index;
	int	sum;
	int	i;

	sum = 0;
	i = -1;
	index = *(int *)arg;
	if (index == 0)
	{
		while (++i < 5)
			sum += primes[i];
	}
	else
	{
		while (++i < 10)
			sum += primes[i];
		printf("result: %d", sum);
	}
	free(arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	th[2];
	int			*indexs;
	int			i;

	i = -1;
	while (++i < 2)
	{
		indexs = (int *)malloc(sizeof(int));
		if (!indexs)
			return (-1); // ft_error
		*indexs = i;
		if (pthread_create(&th[i], NULL, &routine, indexs) != 0)
			return (-1); // ft_error
	}
	i = -1;
	while (++i < 2)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (-1); // ft_error
	}
	return (0);
}
