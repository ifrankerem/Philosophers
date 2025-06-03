#include "asd.h"
#include <sys/types.h>
#include <sys/wait.h>

pthread_mutex_t	water_mutex;
pthread_mutex_t	fuel_mutex;
int				water;
int				fuel;

water = 10;
fuel = 50;
void	*routine(void *arg)
{
	if (rand() % 2 == 0)
	{
		pthread_mutex_lock(&water_mutex);
		sleep(1); // yeteri kadar zaman verelim ki locku attıktan sonra diğer thread de lock atsın deadlocku daha rahat görelim
		pthread_mutex_lock(&fuel_mutex);
	}
	else
	{
		pthread_mutex_lock(&fuel_mutex);
		sleep(1);
		pthread_mutex_lock(&water_mutex);
	}
	fuel += 50;
	water = fuel;
	printf("Fuel incremented : %d and water set to :%d\n", fuel, water);
	pthread_mutex_unlock(&water_mutex);
	pthread_mutex_unlock(&fuel_mutex);
}

int	main(void)
{
	pthread_t	th[8];
	int			i;

	i = -1;
	pthread_mutex_init(&water_mutex, NULL);
	pthread_mutex_init(&fuel_mutex, NULL);
	while (++i < 8)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			return (-1); // ft_error
	}
	i = -1;
	while (++i < 8)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (-1); // ft_error
	}
	printf("Fuel: %d Water: %d\n", fuel, water);
	pthread_mutex_destroy(&water_mutex);
	pthread_mutex_destroy(&fuel_mutex);
}
/* 
    burda konsept şu thread 1 diyelim ki wateri locklasın thread 2 de calısmaya baslıcak arada sleep oldugundan thread 2 şansa 
    if-else in diğer blogunu okursa bu sefer de oda fueli locklicak böyle bi durumda thread 1 fueli değiştirmek istediğinde
    thread 2 nin unlock yapmasını beklemesi gerekiyor aynı şekilde thread 2 de wateri değiştirmek istediğinde thread 1 in unlock
    etmesini beklemek zorunda bu sekilde sonsuz döngüye girerler deadlock olur yani aslında ana mantık threadlerin birbirlirleinin
    resource (burda örnekte mutex) lerini beklemelerinden sonsuz döngüye kilide girmelerine denir bizim philo projesinde deadlocka
    giren şey çatallar oluyor

/*/