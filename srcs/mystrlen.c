#include <stddef.h>

int mystrlen(char *str)

{
    int i = 0;

    if (str == NULL)
        return -84;
    for (; str[i] != '\0'; i+=1);
    return i;    
}