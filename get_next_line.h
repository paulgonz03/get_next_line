#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <limits.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *get_next_line(int fd);
char *extract_line(char *aux_read);
char *remove_first_line(char *statica);
int mystrlen(char *str);
char *mystrjoin(char *statica, char *aux_read);
char *get_read(int fd, char *statica);
int mystrchr(const char *src, int c);

#endif
