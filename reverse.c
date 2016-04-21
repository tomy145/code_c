#include <stdio.h>

char * reverse(char* s)
{
    if( (s != NULL) && (*s != '\0') )
    {
        reverse(s + 1);
        
        printf("%c", *s);

        return reverse(s + 1);
    }
    else
    {
        return NULL;
    }
    

}

int main()
{
    char *ch  = reverse("12345");
    
    printf("ch --- %s\n",*ch);
    
    return 0;
}
