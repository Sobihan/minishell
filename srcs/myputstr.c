#include <unistd.h>

void myputchar(char c)
{
    write(1, &c, 1);
}

void myputstr(char *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i] != '\0'; i += 1) {
        myputchar(str[i]);
    }
}