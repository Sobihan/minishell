#include "env.h"
#include <stdlib.h>

void myputstr(char *str);
void myputchar(char c);

void printenv(env_t *envp)
{
    env_t *current = envp;
    for (; current->next != NULL; current = current->next) {
        myputstr(current->str);
        myputchar('\n');
    }

}