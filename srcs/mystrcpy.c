#include <stdlib.h>

int mystrlen(char *str);

char *my_strcpy(char *str)
{
    int size = mystrlen(str);
    char *copy = malloc(sizeof(char) * (size + 1));

    for (int i = 0; str[i] != '\0'; i = i + 1)
        copy[i] = str[i];
    copy[size] = '\0';
    return (copy);
}