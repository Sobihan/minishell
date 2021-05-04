#include "env.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strcpy(char *str);

env_t *init_pointer(char *str)
{
    env_t *list = malloc(sizeof(env_t));
    list->str = str;
    list->next = NULL;
    return list;
}

env_t *add_value(env_t *list, char *str)
{
    env_t *current = list;

    for (; current->next != NULL; current = current->next);

    current->next = malloc(sizeof(env_t));
    current->next->str = str;
    current->next->next = NULL;
    return current;
}

env_t *copy_env(char **env)
{
    env_t *list = init_pointer(env[0]);
    for (int i = 1; env[i]; i += 1)
        add_value(list, my_strcpy(env[i]));
    
    return list;
}