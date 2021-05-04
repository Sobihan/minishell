#include <stdlib.h>

int count_word(char *str, char separator)
{
    int word = 0;
    int k = 0;
    int i = 0;

    for (;str[i] == separator && str[i] != '\0'; i = i + 1) {}
    for (; str[i] != '\0'; i = i + 1) {
        for (;str[i] == separator && str[i] != '\0'; i = i + 1) {}
        for (k = 0; str[i] != '\0' && str[i] != separator; i = i + 1)
            k = k + 1;
        if (k > 0)
            word = word + 1;
        if (str[i] == '\0')
            return (word);
    }
    return word;
}

char **replace(char **array, char  *str, char separator)
{
    int word = 0;
    int character = 0;
    int i = 0;

    for (;str[i] == separator && str[i] != '\0'; i = i + 1) {}
    for (; str[i] != '\0'; i = i + 1) {
        for (;str[i] == separator && str[i] != '\0'; i = i + 1) {}
        for (character = 0; str[i] != '\0' && str[i] != separator; i = i + 1) {
            array[word][character] = str[i];
            character = character + 1;
        }
        if (str[i] == '\0')
            return (array);
        word = word + 1;
    }
    return (array);
}

char **malloc_array(char *str, char separator, char **array)
{
    int i = 0;
    int k = 0;
    int j = 0;

    for (;str[i] == separator && str[i] != '\0'; i = i + 1) {}
    for (; str[i] != '\0'; i = i + 1) {
        for (;str[i] == separator && str[i] != '\0'; i = i + 1) {}
        for (; str[i] != '\0' && str[i] != separator; i = i + 1)
            k = k + 1;
        if (k > 0) {
            array[j] = malloc(sizeof(char) * (k + 1));
            array[j][k] = '\0';
            k =  0;
            j = j + 1;
        }
        if (str[i] == '\0')
            break;
    }
    return (array);
}

char **wordarray(char *str, char separator)
{
    int nbr_words = count_word(str, separator);
    char ** array = malloc(sizeof(char *) * (nbr_words + 1));

    if (str == NULL) {
        free(array);
        return (NULL);
    }
    array[nbr_words] = NULL;
    array = replace(malloc_array(str, separator, array), str, separator);
    return (array);
}