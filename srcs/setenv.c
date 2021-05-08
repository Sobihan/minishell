
int myarraylen(char **array);

void mysetenv(char **input, env_t *envp)
{
    if (myarraylen(input) <= 1)
        return;
    printf("%d\n", myarraylen(input));
}