//
//  main.c
//  fileio
//
//  Created by Mac on 16/6/30.
//  Copyright © 2016年 Mac. All rights reserved.
//
//
//#include <stdio.h>
//#include <sys/types.h>
//#include <fcntl.h>
//#include <sys/stat.h>
//#include <unistd.h>
//#include <string.h>
//
//int main(int argc, const char * argv[])
//{
//
//    char *pathName = "abc.c";
//
//    int fd = -1;
//    fd = open(pathName, O_RDWR);
//
//    if (fd == EOF)
//    {
//        printf("open erroe !\n");
//    }
//    else
//    {
//        printf("open successd! \n");
//
//        //追加文字
//         char *str = "#include <stdio.h> \n int main(int argc,const char *argv[]) \n { \n }" ;
//        
//       ssize_t len = write(fd, str,strlen(str));
//
//        printf("len = %zd\n",len);
//
//    }
//
//    close(fd); //关闭文件
//
//    
//
//
//    return 0;
//}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{

    char buf[10];
    size_t n;

    n = read(STDIN_FILENO, buf,n);
    if (n < 10)
    {
        perror("read STDIN_FILENO");
        exit(-1);
    }

    write(STDOUT_FILENO, buf, n);



    return 0;
}