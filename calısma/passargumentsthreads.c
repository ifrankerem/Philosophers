#include "asd.h"
#include <sys/types.h>
#include <sys/wait.h>

//? Problem : 10 thread yarat bu threadler her biri bu prime dizisinden ayrı elemanlar alıp ekrana yazdırsın

int		primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	index;

	index = *(int *)arg;
	/* void *ı önce int *olarak değiştirip yani cast edip sonra *koyarak basına değerini alıyoruz */
	printf("%d ", primes[index]);
	free(arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	th[10];
	int			*indexs;
	int			i;

	/* 1. çözüm (gpt) indexes[i] = i dersen bu sorunu çözersin stackte olsa bile her biri ayrı adreslenmis olucak
	bu nedenle her bir thread ayrı olarak bir adres olmus oluyor sorun çözülmüs oluyor
	2. çözüm malloc ile çözmek bu sefer malloc ile heapte her birine bir yer ayırmıs olursun aynı mantıktan her bir thread ayrı bir
	index kaazanmıs olur bu sayede de unique olur fakat burda tek sorun nerde freeleceğin gidipte routine içinde freelemen gerekir!
    3. çözüm mutex gidipte routine içinde i yi mutexle locklaayıp unlocklasaydık da olurdu diyor gpt
	*/
	i = -1;
	while (++i < 10)
	{
		indexs = (int *)malloc(sizeof(int));
		if (!indexs)
			return (-1); // ft_error
		*indexs = i;
		if (pthread_create(&th[i], NULL, &routine, indexs) != 0)
			return (-1); // ft_error
	}
	i = -1;
	while (++i < 10)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (-1); // ft_error
	}
	return (0);
}

/* Burda sorun su threadler kafasına göre calıstıklarından dolayı stackteki i adresini sen bu fonksiyona verdiğinde
o adresteki değer değiştiğinde threadler bunu sırayla almıyor veya  cok daha saçma değerleri alıyor atıyorum
i = 5 değerinde thread 5 belki hiç calısmaıs bile olabilir olay thread 5 olması da değil thread 5 onu alana kadar belki
i = 7 değerini vericek bu nedenle ordaki while döngüsünün hızı ile threadlerin calısma mantıgı uyusmuyor yukarda 1-2 çözüm yazdım!

*/