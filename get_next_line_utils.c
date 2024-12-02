/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:19:48 by paulgonz          #+#    #+#             */
/*   Updated: 2024/12/02 19:52:26 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	mystrlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*mystrjoin(char *statica, char *aux_read)
{
	int		i;
	int		j;
	char	*new_static;

	i = 0;
	j = 0;
	new_static = malloc((mystrlen(statica) + mystrlen(aux_read) + 1)
			* sizeof(char));
	if (!new_static)
		return (free(statica), NULL);
	while (statica[i])
	{
		new_static[i] = statica[i];
		i++;
	}
	while (aux_read[j])
		new_static[i++] = aux_read[j++];
	new_static[i] = '\0';
	free(statica);
	return (new_static);
}

int	mystrchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*aux_get_read(int fd, char *statica, char *aux_read)
{
	int	val_read;

	val_read = 1;
	while (val_read != 0 && !mystrchr(statica, '\n'))
	{
		val_read = read(fd, aux_read, BUFFER_SIZE);
		if (val_read < 0)
			return (free(statica), free(aux_read), statica = NULL);
		aux_read[val_read] = '\0';
		statica = mystrjoin(statica, aux_read);
		if (!statica)
			return (free(statica), free(aux_read), statica = NULL);
	}
	free(aux_read);
	return (statica);
}
