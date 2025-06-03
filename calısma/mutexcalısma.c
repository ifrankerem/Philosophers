#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t	atm_lock;

void	*func(void *isim)
{
	char	*ad;

	ad = (char *)isim;
	printf("%s ATM sırasına girdi \n", ad);
	pthread_mutex_lock(&atm_lock);
	printf("%s ATM ye giriş yaptı \n", ad);
	usleep(1000000);
	printf("%s ATM de işlemi bitti cıkıyo \n", ad);
	pthread_mutex_unlock(&atm_lock);
	return (NULL);
}

int	main(void)
{
	pthread_t a, b, c;
	pthread_mutex_init(&atm_lock, NULL);

	pthread_create(&a, NULL, func, "Aleyna");
	pthread_create(&b, NULL, func, "Kerem");
	pthread_create(&c, NULL, func, "Atakan");

	pthread_join(a, NULL);
	pthread_join(b, NULL);
	pthread_join(c, NULL);

	pthread_mutex_destroy(&atm_lock);
	return (0);
}