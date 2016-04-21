#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	ints=1,h = 0;
	int i, j;
	scanf("%d", &h);
	printf("1\n");

	for(i=2;i<=h;s=1,i++)
	{
		printf("1 ");
		for(j=1;j<=i-2;j++)
		{
			printf("%d ", (s = (i - j) * s / j));
		}          
    	printf("1\n");
	}

	getchar();

	return 0 ;
}
