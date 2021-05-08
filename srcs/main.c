#include <stdio.h>
#include "env.h"
#include <stdlib.h>

env_t *copy_env(char **env);
void myputstr(char *str);
char **wordarray(char *str, char separator);
int mystrcmp(char *str, char *str1);
void printenv(env_t *envp);
int mystrlen(char *str);
void mysetenv(char **input, env_t *envp);

void parser(env_t *envp, char **input)
{
    if (mystrcmp(input[0], "exit"))
        exit(0);
    if (mystrcmp(input[0], "env"))
        printenv(envp);
    if (mystrcmp(input[0], "setenv"))
       mysetenv(input, envp);
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