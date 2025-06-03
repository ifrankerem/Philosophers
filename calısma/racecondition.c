#include "asd.h"
#include <sys/types.h>
#include <sys/wait.h>

int		mails = 0;

void	*routine(void *arg)
{
	int	i;

	i = 0;
	while (i < 100000)
	{
		mails++;
		i++;
	}
}
int	main(void)
{
	pthread_t t1, t2;
	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1); // ft_error
	if (pthread_create(&t2, NULL, &routine, NULL))
		return (1); // ft_error
	if (pthread_join(t1, NULL))
		return (1); // ft_error
	if (pthread_join(t2, NULL))
		return (1); // ft_error
	printf("Number of mails: %d\n", mails);
	return (0);
}

//! expected cıktı 2000000 olmalıydı fakat cıktı daha farklı cıkıyor bunun nedeni ise race condition!
/* threadler sıra sıra calıstıgında bir sıkıntı olmaz
fakat 2 threadde aynı aanda calıstıgında işler sarpa sarar eğer 100 iterasyondan fazla ise
cünkü 2 threaddde burda maails sayısını basta alıcak ve örneğint t1 calısırken t2 durabilir bu senaryoda
t2 registerda kalan değeri yani aslında ilk aldıkları değeri baz alıcak t1 ın arttırdıgı değerden devam etmeyecek
bu nedenle ise değer azalısı yaşanıcak finalde


*/ 