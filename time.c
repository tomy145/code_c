/*************************************************************************
	> File Name: time.c
	> Author: 
	> Mail: 
	> Created Time: 三  7/ 6 19:11:57 2016
 ************************************************************************/

#include <stdio.h>
#include <time.h>



int main(int argc, const char *argv[])
{
    time_t t1;
    
    time(&t1);

    printf("t1 = %d\n",t1);
    printf("timestr --- %s\n",ctime(&t1));

    struct tm *t2 = gmtime(&t1);
    
    printf("tm_sec = %d\n",t2->tm_sec);
    printf("tm_min = %d\n",t2->tm_min);
    printf("tm_hour = %d\n",t2->tm_hour);
    printf("tm_mday = %d\n",t2->tm_mday);
    printf("tm_mon = %d\n",t2->tm_mon);
    printf("tm_year = %d\n",t2->tm_year+1900);
    printf("tm_wday = %d\n",t2->tm_wday);
    printf("tm_yday = %d\n",t2->tm_yday);
    printf("tm_isdst = %d\n",t2->tm_isdst);


	return 0;
}
