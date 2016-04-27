#include <stdio.h>

int main(void)
{
    int year, N, month, day, i, d, a = 1;

    printf("Please input the number of the year:\n");
    scanf("%d", &year);
    printf("Please input N:\n");
    scanf("%d", &N);

    int p[2][12] =
    {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    };

    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        a = 0;

    for (i = 0; i < 12; i++)
    {
        if (N - p[a][i] <= 0)
        {
            month = i + 1;
            day = N;
            break;
        } else
            N -= p[a][i];

    }

    /*    for (i = 1; i <= 12; i++) {
          switch(i) {
          case 1:
          case 3:
          case 5:
          case 7:
          case 8:
          case 10:
          case 12:
          d = 31;
          break;
          case 4:
          case 6:
          case 9:
          case 11:
          d = 30;
          break;
          case 2:
          {
          if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
          d = 29;
          break;
          } else {
          d = 28;
          break;
          }
          }
          default:
          printf("error\n");
          }

          if (N - d <= 0) {
          month = i;
          day = N;
          break;
          } else
          N -= d;
          }
          */

    printf("month = %d\nday = %d\n", month, day);
    return 0;
}

