#ifndef ENV_H_
#define ENV_H_

typedef struct env
{
    char *str;
    struct env *next;
} env_t;

#endif