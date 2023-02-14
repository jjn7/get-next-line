/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:14:43 by jnottle           #+#    #+#             */
/*   Updated: 2023/01/25 16:46:19 by jnottle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned int		i;
	unsigned char		*dest;
	unsigned const char	*str;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	i = 0;
	dest = (unsigned char *)str1;
	str = (unsigned char *)str2;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)str + i);
		i++;
	}
	return (dest);
}

static char	*extract_new_line(char *line)
{
	char	*rest_of_line;
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	rest_of_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*rest_of_line == '\0')
	{
		free(rest_of_line);
		rest_of_line = NULL;
	}
	line[i + 1] = '\0';
	return (rest_of_line);
}

static char	*find_new_line(int fd, char *buffer, char *backup)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	line = find_new_line(fd, buffer, backup);
	free(buffer);
	if (!line)
		return (line);
	backup = extract_new_line(line);
	return (line);
}
