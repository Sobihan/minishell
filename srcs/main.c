#include <stdio.h>
#include "env.h"
#include <stdlib.h>

env_t *copy_env(char **env);
void myputstr(char *str);
char **wordarray(char *str, char separator);
int mystrcmp(char *str, char *str1);

void parser(env_t *envp, char **input)
{
    if (mystrcmp(input[0], "exit"))
        exit(0);
    /*TODO: env, setenv*/
}

int main(int ac, char **av, char **env)
{
    size_t value = 0;
    char *str = NULL;
    size_t len = 0;
    char **input = NULL;

    env_t *envp = copy_env(env);
    while (1) {
        myputstr("$>");
        value = getline(&str, &len, stdin);
        str[mystrlen(str) - 1] = '\0';
        input = wordarray(str, ' ');
        parser(envp, input);
    }
}