#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*func(void *arg)
{
    arg = NULL;
	printf("deneme123\n");
	sleep(5);
	printf("3162\n");
}

int	main(void)
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, &func, NULL);
	pthread_create(&t2, NULL, &func, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return (0);
}