#include "get_next_line.h"

char *extract_line(char *aux_read)
{
    int i;
    char *aux;

    i = 0;
    while (aux_read[i] != '\0' && aux_read[i] != '\n')
        i++;
    aux = malloc((i + 1) * sizeof(char));
    if(!aux)
        return(0);
    i = 0;
    while (aux_read[i] != '\0' && aux_read [i]!= '\n')
    {
        aux[i] = aux_read[i];
        i++;
    }
    aux[i] = '\0';
    return(aux);
}
char *remove_first_line(char *statica)
{
    char *new_static;
    int i;
    int j;
    int k;
    int len_new_static;

    len_new_static = 0;
    i = 0;
    j = 0;
    while (statica[i] != '\0' && statica[i] != '\n')
        i++;
    i++;
    k = i;
    while (statica[i] != '\0')
    {
        i++;
        len_new_static++;
    }
    new_static = malloc ((len_new_static + 1) * sizeof(char));
    if(!new_static)
        return (0);
    while (statica[k] != '\0')
        new_static[j++] = statica[k++];
    new_static[j] = '\0';
    return(new_static);
}

char *get_read(int fd, char *statica)
{
    int val_read;
    char aux_read[BUFFER_SIZE];
    
    val_read = 1;
    if(statica == NULL)
    {
        statica = malloc(BUFFER_SIZE *sizeof(char));
        if(!statica)
            return (0);
        statica[0] = '\0';
    }
    while(val_read != 0 && !mystrchr(statica, '\n'))
    {
        val_read = read(fd, aux_read, BUFFER_SIZE);
        aux_read[val_read] = '\0';
        statica = mystrjoin(statica, aux_read);
    }
    return(statica);
}
char *get_next_line(int fd)
{
    static char *statica;
    char *line;

    line = NULL;
    statica = NULL;
    statica = get_read(fd, statica);
    if(!statica)
    {
        free(statica);
        return (0);
    }
    line = extract_line(statica);
    statica = remove_first_line(statica);
    return (line);
}

// int main()
// {  
//     int fd;

//     fd = open ("hola", O_RDONLY);
//     printf ("..%s\n", get_next_line(fd));
//     printf ("..%s\n", get_next_line(fd));
//     printf ("..%s\n", get_next_line(fd));
//     close(fd);
// }

