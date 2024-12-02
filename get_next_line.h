/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:19:35 by paulgonz          #+#    #+#             */
/*   Updated: 2024/12/02 19:52:14 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*extract_line(char *aux_read);
char	*remove_first_line(char *statica);
int		mystrlen(char *str);
char	*mystrjoin(char *statica, char *aux_read);
char	*get_read(int fd, char *statica);
int		mystrchr(const char *src, int c);
char	*aux_get_read(int fd, char *statica, char *aux_read);

#endif
