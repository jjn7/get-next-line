/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:58 by jnottle           #+#    #+#             */
/*   Updated: 2023/01/20 09:53:09 by jnottle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (s2 == NULL)
		return (NULL);
	if (!s2)
		return (0);
	s2 = ft_memcpy(s2, s1, len);
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			s;
	int			s1len;
	int			s2len;
	char		*s3;

	i = 0;
	s = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s3 = malloc(s1len + s2len + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[s])
	{
		s3[i + s] = s2[s];
		s++;
	}
	s3[i + s] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s != (char)c)
		return (NULL);
	else
		return ((char *)s);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	s_len;
	char	*str;

	a = 0;
	b = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
	len = s_len - start;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[a])
	{
		if (a >= start && b < len)
			str[b++] = s[a];
	a++;
	}
	str[b] = 0;
	return (str);
}
