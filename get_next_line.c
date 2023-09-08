/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:29:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/25 18:34:40 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*next;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next = ft_read(fd, next);
	if (!next)
	{
		free(next);
		next = NULL;
		return (NULL);
	}
	line = ft_get_line(next);
	next = ft_get_rest(next);
	return (line);
}

char	*ft_read(int fd, char *next)
{
	char	*buf;
	char	*temp;
	long	bytes_readed;

	buf = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buf)
		return (NULL);
	temp = NULL;
	while (ft_strchr(next, '\n') == 0)
	{
		bytes_readed = read(fd, buf, BUFFER_SIZE);
		if (bytes_readed == 0)
			break ;
		if (ft_check_errors(bytes_readed, next, buf, temp) == 0)
			return (NULL);
		temp = next;
		buf[bytes_readed] = '\0';
		next = ft_strjoin(next, buf);
		free(temp);
	}
	free(buf);
	return (next);
}

int	ft_check_errors(long bytes_readed, char *aux, char *buf, char *temp)
{
	if ((aux != NULL && aux[0] == '\0') || bytes_readed == -1)
	{
		free(temp);
		free(buf);
		free (aux);
		return (0);
	}
	return (1);
}

char	*ft_get_line(char *str)
{
	char	*aux;
	int		index;
	int		len;

	len = 0;
	index = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	aux = ft_substr(str, index, len + 1);
	return (aux);
}

char	*ft_get_rest(char *str)
{
	char	*aux;
	int		index;
	int		len;

	len = 0;
	index = ft_strlen (str);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
		len ++;
	if (str[len] != '\0')
	{
		aux = ft_substr(str, len, index - len);
	}
	else
		aux = NULL;
	free (str);
	return (aux);
}
