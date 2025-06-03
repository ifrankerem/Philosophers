#include "asd.h"
#include <sys/types.h>
#include <sys/wait.h>

int				mails = 0;
pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&mutex);
	while (++i < 100000000)
		mails++;
	pthread_mutex_unlock(&mutex);
}
int	main(void)
{
	pthread_t	th[8]; //! *th yapcak olsaydın malloc ile 8 lik yer acman gerekirdi direkt böyle arrayda ztn acmıs oluyorsun!!!
	int			i;

	i = -1;
	pthread_mutex_init(&mutex, NULL);
	while (++i < 8)
	{
		pthread_create(&th[i], NULL, &routine, NULL);
		printf("Thread number %d created\n", i);
	}
	i = -1;
	while (++i < 8)
	{
		pthread_join(th[i], NULL);
		printf("Thread number %d executed\n", i);
	}
	printf("Number of mails: %d\n", mails);
	pthread_mutex_destroy(&mutex);
	return (0);
}
/* burda kritik nokta pthread_create ile pthread_joini aynı while döngüsüne almaman laızm
cünkü alırsan her create den sonra join edersin bu sefer multithread mantıgı kalmaz tüm
threadler aynı anda baslıcak ondan sonra hepsi aynı anda işleme giricek ve bu arada
printf("executed") deki 0 dan 7 ye kadar olan sıra da aslında biz while döngüsünde i arttırdıgımız için
yani önce thread 7 işlemini bitirmiş olabilir fakat önce 0 olan basılıyor printf while döngüsü oldugundan
yani ordaki sıra threadlerin işlem sırasını belirtmiyor!
*/