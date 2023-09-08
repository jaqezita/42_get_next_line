/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:47:02 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/22 19:40:57 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s != NULL && s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index_suf;
	int		index;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!result)
		return (NULL);
	index_suf = 0;
	index = 0;
	while (s1 != NULL && s1[index] != '\0')
	{
			result[index] = s1[index];
			index++;
	}
	while (s2 != NULL && s2[index_suf] != '\0')
	{
			result[index] = s2[index_suf];
			index++;
			index_suf++;
	}
	result[index] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s_copy;

	s_copy = (char *)s;
	while (s_copy != NULL && *s_copy)
	{
		if (*s_copy == (char)c)
			return (s_copy);
		s_copy++;
	}
	if ((unsigned char)c == '\0')
		return (s_copy);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*substr;
	char			*str;

	index = 0;
	str = "\0";
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc((len + 2) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start] != '\0' && index < len)
	{
		substr[index] = s[start];
		start++;
		index++;
	}
	substr[index] = '\0';
	return (substr);
}
