#include "get_next_line.h"

static char *read_to_buff(int fd, char *buffer);
static char *extract_remove(char **buffer);
static char *remove_line(char *buffer);


char *get_next_line(int fd)
{
    static char *buffer;

    if(!ft_strchr(buffer, '\n'))
        buffer = read_to_buff(fd, buffer);
    return extract_remove(&buffer);
}

static char *read_to_buff(int fd, char *buffer)
{
    char *read_buffer;
    int read_check;

    read_buffer = malloc(BUFFER_SIZE + 1);
    do
    {
        read_check = read(fd, read_buffer, BUFFER_SIZE);
        if (read_check == -1)
        {
            free(read_buffer);
            return NULL;
        }
        read_buffer[read_check] = 0;
        if (ft_strlen(read_buffer))
            buffer = ft_strjoin_s(buffer, read_buffer);
    } while (!ft_strchr(read_buffer, '\n') && read_check == BUFFER_SIZE);   
    free(read_buffer);
    return buffer;
}

static char *extract_remove(char **buffer)
{
    char *line;
    int i;

    if(ft_strchr(*buffer, '\n'))
        line = malloc(ft_strchr(*buffer, '\n') - *buffer + 2);
    else if(*buffer)
        line = malloc(ft_strlen(*buffer) + 1);
    else
        return NULL;
    i = 0;
    while((*buffer)[i])
    {

        line[i] = (*buffer)[i];
        i++;
        if((*buffer)[i - 1] == '\n')
            break;
    }
    line[i] = 0;
    *buffer = remove_line(*buffer);
    return line;
}

static char *remove_line(char *buffer)
{
    char *new_buffer;
    int i;
    int j;

    if(ft_strchr(buffer, '\n'))
    {
        i = ft_strchr(buffer, '\n') - buffer + 1;
        j = 0;
        new_buffer = malloc(ft_strlen(&buffer[i]) + 1);
        while(buffer[i])
            new_buffer[j++] = buffer[i++];
        new_buffer[j] = 0;
    }
    else
        new_buffer = NULL;
    free(buffer);
    return new_buffer;
}