#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp
#include <sys/stat.h> //stat
#include <dirent.h>

int getFileCountInDir(const char *path, int *pcount)
{
    int ret = 0;
    DIR *dirp = NULL;
    struct dirent *dir = NULL;
    char buf[256] = {0};

    if (path == NULL || pcount == NULL)
    {
        ret = -1;
        goto End;
    }

    dirp = opendir(path);
    if (dirp == NULL)
    {
        perror("func opendir error");
        exit(-1);
    }

    while ((dir = readdir(dirp)) != NULL)
    {
        struct stat st;
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;

        sprintf(buf,"%s/%s", path, dir->d_name);
        printf("buf:%s\n", buf);

        if (stat(buf, &st) == -1)
        {
            perror("func stat error");
            exit(-1);
        }

        if (((st.st_mode & S_IFMT) == S_IFDIR))
        {
            getFileCountInDir(buf, pcount);
        }
        else
            //*pcount++;//error
            (*pcount)++;
    }

    closedir(dirp);
End:
    return ret;
}

int main(int argc, char **argv)
{
    int count = 0;
    getFileCountInDir(argv[1], &count);

    printf("count:%d\n", count);
    return 0;
}
