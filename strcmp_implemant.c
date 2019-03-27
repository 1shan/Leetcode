#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 50
int strcmp_implement(char*, char*);

int strcmp_implement(char *str1, char *str2)
{

    while (*str1 != '\0' || *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            if (*str1 > *str2)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        *str1++;
        *str2++;
    }
    return 0;
}
int main()
{
    char str1[MAXSIZE];
    char str2[MAXSIZE];
    
    int result = strcmp_implement(str1, str2);

    printf("result = %d",result);

    return 0;
}