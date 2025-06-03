#include "asd.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void	*roll_dice(void *arg)
{
	int	value;
	int	*result;

	value = ((rand() % 6) + 1);
	/* zarın 1 den 6 ya kadar değerleri işte rand = random % 6
		+1 direkt 0-6 arasında random no vercek */
	result = malloc(sizeof(int)); /* heapte yer acmalısın yoksa stackteki veri fonksiyondan cıktıgında silinecekti bu nedenle 
    heapte tutup öyle return etmeli cünkü burda roll_dice fonksiypnu bu veriyi int value diyince lokalde tuutyor sadece  */
	*result = value;
	printf("Func adress result: %p\n", result);
	return ((void *)(result));
	// direkt & value de olurdu (void *) yazmaya gerek yoktu ama olsun casting ettik
}

int	main(void)
{
	srand(time(NULL)); // rand fonksiyonu için seed önemsiz!
	int *res;
	pthread_t th;
	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		return (1); // ft_error

	if (pthread_join(th, (void **)&res) != 0)
		// &res cünkü **void alıyor bu thread de önceki fonksiyondan return değerini almalı mantıken!
		return (1); // ft_error
	printf("Func adress result: %p\n", res);
	printf("Result: %d\n", *res);
	free(res);
		// freelemeyi unutma roll_dice fonksiyonunda freeleyemedeiğinden burda yapmalısın cünkü orda return ettin!
}