#include <stddef.h>

int mystrlen(char *str);

int mystrcmp(char *str, char *str1)
{
    if (str == NULL || str1 == NULL)
        return -1;
    if (mystrlen(str) != mystrlen(str1))
        return 0;
    for (int i = 0; str[i] != '\0'; i+= 1) {
        if (str[i] != str1[i])
            return 0;
    }
    return 1;
}