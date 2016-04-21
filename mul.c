

#include <stdio.h>

int main(void)
{
	int i = 1 , j = 1 ;

	while(i < 10)
	{
		j = 1;
		while(j < i)
		{
			printf("\t %d x %d = %d \n",i,j,i*j);
			++j;
		}
		printf("\n");
		++i;
	}

	return 0;
}