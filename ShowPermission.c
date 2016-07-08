
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void showPermission(const char *name,char *buf)
{
    struct stat st_buf;
    int val = 0;
    val = stat(name,&st_buf);
    if(val == 0)
    {
        mode_t t = st_buf.st_mode;
        printf("st_mode = %d\n",t);
        mode_t temp = t &00777;

        int i = 0;
        char str_buf[10] = {0};
        for(i = 0; i < 9;++i)
        {
            unsigned int tempValue = 0;
            tempValue = 1 << 8 - i;
            unsigned int t1 = temp & tempValue;
            printf("t1 = %d\n \t tempValue = %d\n",t1,tempValue);
            switch(i)
            {
                case 0:
                {
                    if(t1 == tempValue)
                    {
                        str_buf[0] = 'r';
                    }
                    else
                    {
                        str_buf[0] = '-';
                    }
                    
                }
                break;
                case 1:
                {
                    if(t1 == tempValue)
                    {
                        str_buf[1] = 'w';
                    }
                    else
                    {
                        str_buf[1] = '-';
                    }
                }
                break;
                case2:
                {
                   if(t1 == tempValue)
                    {
                        str_buf[2] = 'x';
                    }
                    else
                    {
                        str_buf[2] = '-';
                    } 
                }
                break;
                case 3:
                {
                    if(t1 == tempValue)
                    {
                        str_buf[3] = 'r';
                    }
                    else
                    {
                        str_buf[3] = '-';
                    }
                }
                break;
                case 4:
                {
                    if(t1 == tempValue)
                    {
                        str_buf[4] = 'w';
                    }
                    else
                    {
                        str_buf[4] = '-';
                    }
                }
                break;
                case 5:
                {
                    if(t1 == tempValue)
                    {
                        str_buf[5] = 'x';
                    }
                    else
                    {
                        str_buf[5] = '-';
                    }
                }
                break;
                case 6:
                {
                    if(t1 == tempValue)
                    {
                        str_buf[6] = 'r';
                    }
                    else
                    {
                        str_buf[6] = '-';
                    }
                }
                break;
                case 7:
                {
                    if(t1 == tempValue)
                    {
                        str_buf[7] = 'w';
                    }
                    else
                    {
                        str_buf[7] = '-';
                    }
                }
                break;
                case 8:
                {
                    if(t1 == tempValue)
                    {
                        str_buf[8] = 'x';
                    }
                    else
                    {
                        str_buf[8] = '-';
                    }
                }
                break;
                default:
                break;
            }

            printf("mo = %d\n",1 << i);
        }

        strcpy(buf,str_buf);

    }
    else
    {
        printf("文件权限获取出错!\n");
    }

    printf(" 权限位 = %s\n",buf);

}

int main(int argc, const char * argv[])
{
    char *pathName = "./abc.c";
    
    char perStr[100] = {0};

    showPermission(pathName,perStr);


    return 0;
}
