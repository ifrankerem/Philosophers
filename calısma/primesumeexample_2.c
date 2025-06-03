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
	while (++i < 5)
		sum += primes[index + i];
	*(int *)arg = sum;
	return (arg);
}

int	main(void)
{
	pthread_t	th[2];
	int			*indexs;
	int			i;
	int			*r;
	int			finalsum;

	i = -1;
	while (++i < 2)
	{
		indexs = (int *)malloc(sizeof(int));
		if (!indexs)
			return (-1); // ft_error
		*indexs = i * 5;
		if (pthread_create(&th[i], NULL, &routine, indexs) != 0)
			return (-1); // ft_error
	}
	i = -1;
	finalsum = 0;
	while (++i < 2)
	{
		if (pthread_join(th[i], (void **)&r) != 0)
			return (-1); // ft_error
		finalsum += *r;
		free(r);
	}
	printf("result: %d", finalsum);
	return (0);
}
