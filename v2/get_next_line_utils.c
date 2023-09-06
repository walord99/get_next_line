#include "get_next_line.h"

char *ft_strchr(char *str, char c)
{
    int i;

    if(!str)
        return NULL;
    i = 0;
    while(str[i])
    {
        if (str[i] == c)
            return &str[i];
        i++;
    }
    return NULL;
}

int ft_strlen(char *str)
{
    int i;
    
    if (!str)
        return 0;
    i = 0;
    while(str[i])
        i++;
    return i;
}

char *ft_strjoin_s(char *s1, char *s2)
{
    char *new_str;
    int i;
    new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);

    i = 0;
    if(s1)
    {
        while(s1[i])
        {
            new_str[i] = s1[i];
            i++;
        }
        free(s1);
    }
    if(s2)
    {
        while(*s2)
            new_str[i++] = *s2++;
    }
    new_str[i] = 0;
    return new_str;
}   