/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:24:26 by dgargant          #+#    #+#             */
/*   Updated: 2024/05/02 14:49:12 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_read_and_fill(int fd, char *buffer, char *backup)
{
	ssize_t	nr_bytes;
	char	*temporal;

	nr_bytes = 1;
	while (nr_bytes > 0)
	{
		nr_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nr_bytes == -1)
			return (NULL);
		else if (nr_bytes == 0)
			break ;
		buffer[nr_bytes] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temporal = backup;
		backup = ft_strjoin(temporal, buffer);
		free(temporal);
		temporal = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_set_line(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (NULL);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - 1);
	if (*tmp == 0)
	{
		free(tmp);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup;

	buffer = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_read_and_fill(fd, buffer, backup);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(line);
		line = NULL;
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = ft_set_line(line);
	return (line);
}
