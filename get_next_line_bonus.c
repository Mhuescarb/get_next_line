/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuescar <mhuescar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:06:18 by mhuescar          #+#    #+#             */
/*   Updated: 2025/03/04 15:04:53 by mhuescar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(char *s, int c);
static char	*ft_substr(char *sub, unsigned int start, size_t lenght);
static char	*fill_line_buffer(int fd, char *left_ch, char *buffer);
static char	*set_line(char *line_buffer);

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			ch;

	i = 0;
	ch = (char) c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ch)
		return ((char *) &s[i]);
	return (NULL);
}

static char	*ft_substr(char *sub, unsigned int start, size_t length)
{
	size_t	i;
	size_t	sub_len;
	char	*str;

	sub_len = 0;
	if (!sub)
		return (NULL);
	sub_len = ft_strlen(sub);
	if (start >= sub_len)
		return (ft_strdup(""));
	if (length > sub_len - start)
		length = sub_len - start;
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = sub[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*fill_line_buffer(int fd, char *left_ch, char *buffer)
{
	ssize_t	b_read;
	char	*temp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free (left_ch);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer [b_read] = 0;
		if (!left_ch)
			left_ch = ft_strdup ("");
		temp = left_ch;
		left_ch = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_ch);
}

static char	*set_line(char *line_buffer)
{
	char	*left_ch;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (NULL);
	left_ch = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i - 1);
	if (*left_ch == 0)
	{
		free (left_ch);
		left_ch = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_ch);
}

char	*get_next_line(int fd)

{
	static char	*left_ch[MAX_FD];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (left_ch[fd]);
		left_ch[fd] = NULL;
		return (NULL);
	}
	buffer = (char *) malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_ch[fd], buffer);
	free(buffer);
	left_ch[fd] = NULL;
	if (!line)
		return (NULL);
	left_ch[fd] = set_line(line);
	return (line);
}
