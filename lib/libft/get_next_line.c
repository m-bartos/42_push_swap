/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:04:49 by mbartos           #+#    #+#             */
/*   Updated: 2023/11/14 11:41:55 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*file_read(char *buffer, int fd)
{
	char	*buffer_add;
	char	*old_buffer;
	int		size;

	buffer_add = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer_add)
		return (NULL);
	size = 1;
	while (ft_strchr(buffer, '\n') == NULL && size != 0)
	{
		size = read(fd, buffer_add, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer_add);
			return (NULL);
		}
		buffer_add[size] = '\0';
		old_buffer = buffer;
		if (old_buffer == NULL)
			old_buffer = (char *) ft_calloc(1, sizeof(char));
		buffer = ft_strjoin(old_buffer, buffer_add);
		free(old_buffer);
	}
	free(buffer_add);
	return (buffer);
}

char	*read_line(char *buffer)
{
	int		i;
	int		len;
	char	*line;

	if (!*buffer)
		return (NULL);
	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0' )
		len++;
	if (buffer[len] == '\n')
		len++;
	line = (char *) ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*remove_line(char *buffer)
{
	char	*temp;

	temp = ft_strchr(buffer, '\n');
	if (temp != NULL)
	{
		temp = ft_strjoin(temp + 1, "");
		free(buffer);
		return (temp);
	}
	else
	{
		free(buffer);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = file_read(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = read_line(buffer[fd]);
	buffer[fd] = remove_line(buffer[fd]);
	return (line);
}
