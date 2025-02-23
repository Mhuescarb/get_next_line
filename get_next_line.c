/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuescar <mhuescar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:03:17 by mhuescar          #+#    #+#             */
/*   Updated: 2025/02/23 20:31:18 by mhuescar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line_buffer(int fd, char *left_ch, char *buffer);
static char	*set_line(char *line_buffer);
static char	*ft_strchr(char *s, int c);
static char	*ft_substr(char *sub, unsigned int start, size_t lenght);

char	*get_next_line(int fd)
{
	static char	*left_ch;
	char		*line;
	char		*buffer;

	buffer = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));//sizeof ?
	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
	{
		free (left_ch);
		free (buffer);
		left_ch = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_ch, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_ch = set_line(line);
	return (line);
}

static char	*set_line(char *line_buffer)
{
	char	*left_ch;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	left_ch = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_ch == 0)
	{
		free (left_ch);
		left_ch = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_ch);
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
	/*
	while (b_read > 0 && !ft_strchr(buffer, '\n'))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_ch);
			return (NULL);
		}
		if (b_read > 0)
			buffer [b_read] = 0;
		if (!left_ch)
			left_ch = ft_strdup("");
		temp = left_ch;
		left_ch = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	if (b_read == 0)
		return (left_ch);
	return (left_ch);
}  */

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

/*char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ch;
	ch = (char) c;
// cast de int a char para incluir chars de más de un byte
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (&s[i]); // no se castea el puntero pq es const char
		i++;
	}
	if (s[i] == ch)
		return (&s[i]);
	return (NULL); 
} */
static char	*ft_substr(char *sub, unsigned int start, size_t lenght)
{
	size_t	i;
	char	*str;

	if (!sub)
		return (NULL);
	if (start > ft_strlen(sub))
		return (malloc (1));
	if (lenght > ft_strlen (sub + start))
		lenght = ft_strlen (sub + start);
	str = malloc((lenght + 1) * sizeof (char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		str[i] = sub[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
 #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"  // Asegúrate de incluir el archivo de encabezado

#define FILE_PATH "text_test.txt"  // Asegúrate de tener un archivo de prueba llamado test.txt

int main()
{
    int fd;
    char *line;

    // Abre el archivo en modo lectura
    fd = open(FILE_PATH, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // Lee el archivo línea por línea utilizando get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        // Imprime la línea leída
        printf("%s", line);
        free(line);  // Libera la memoria de la línea leída
    }

    // Cierra el archivo
    close(fd);

    return (0);
}
*/
