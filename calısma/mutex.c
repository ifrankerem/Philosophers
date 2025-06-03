#include "asd.h"
#include <sys/types.h>
#include <sys/wait.h>

int				mails = 0;
pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	int	i;

	i = -1;
	while (++i < 100000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}
int	main(void)
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1); // ft_error
	if (pthread_create(&t2, NULL, &routine, NULL))
		return (1); // ft_error
	if (pthread_join(t1, NULL))
		return (1); // ft_error
	if (pthread_join(t2, NULL))
		return (1); // ft_error
	printf("Number of mails: %d\n", mails);
	pthread_mutex_destroy(&mutex);
	return (0);
}
/*
    pthread_mutex_lock ve pthread_mutex_unlock arasında yaptıgın işler bir thread o işlevi görürken yani bu örnekte
    mails sayısını arttırıken diğer threadlerim işin içine girip race condition yaptırmamasını saglıyor
    main kısmında ise yazdıgın mutexi tanımlaman ve destroy etmen lazım ki arada malloc kullandıysan lock ve unlock arası leak 
    yememek için yani pthread_mutex_init ve pthread_mutex_destroy gibi. pthread_mutex_init in 2. argümanı aslında mutex konfigirasyonuna yarıyor bu nedenle suanlık
    default istediğimizden null verdik.
*/