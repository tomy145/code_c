#include <stdio.h>

int main(void)
{
    int counter , grade, total = 0,average;
    counter = 0;

    while(counter < 10)
    {
        printf("Enter grader:");
        scanf("%d,&grade");
        total += grade;
        counter++;
    }

    average = total / 10 ;

    printf("Class average is %d\n",average);

return 0;
}
