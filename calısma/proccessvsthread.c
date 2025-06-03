#include "asd.h"
#include <sys/types.h>
#include <sys/wait.h>

void	*routine(void *arg)
{
	arg = NULL;
	printf("Proccess id:%d\n", getpid());
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
	return (0);
}

/*int	main(void)
{
	int pid = fork();
	if (pid == -1)
		return (1);

	printf("Process id %d\n", getpid());
	if (pid != 0)
		wait(NULL);
	return (0);
}

bu direkt process işlemidir burda process id ler farklı geliyor cünkü child process ile  
aslında bi kopya yaratır ve kendisi farklıdır yani aynı belleği taşımazlar
fakat threadler aynı bellek alanını paylaştıgından hem id ler aynı olur 
hem de x= 2 örneğidne oldugu gibi ikiside arttırılıp ekrana yazdırılır.
*/