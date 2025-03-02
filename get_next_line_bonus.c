/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuescar <mhuescar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:06:18 by mhuescar          #+#    #+#             */
/*   Updated: 2025/03/02 20:40:10 by mhuescar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_line_buffer(int fd, char *left_ch, char *buffer);
static char	*set_line(char *line_buffer);
static char	*ft_strchr(char *s, int c);
static char	*ft_substr(char *sub, unsigned int start, size_t lenght);

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
	static char	*left_ch[4096];
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
/*
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int fd1, fd2;
    char *line;

    // Verificar si el usuario pasó dos archivos como argumentos
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <file1_path> <file2_path>\n", argv[0]);
        return 1;
    }

    // Abrir los dos archivos
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error opening file 1");
        return 1;
    }

    fd2 = open(argv[2], O_RDONLY);
    if (fd2 == -1)
    {
        perror("Error opening file 2");
        close(fd1);  // Cerrar fd1 antes de salir
        return 1;
    }

    // Leer y mostrar cada línea del primer archivo
    printf("Reading from file 1 (%s):\n", argv[1]);
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s", line);  // Imprimir la línea leída
        free(line);          // Liberar la memoria de la línea leída
    }

    // Leer y mostrar cada línea del segundo archivo
    printf("\nReading from file 2 (%s):\n", argv[2]);
    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("%s", line);  // Imprimir la línea leída
        free(line);          // Liberar la memoria de la línea leída
    }

    // Cerrar ambos archivos
    close(fd1);
    close(fd2);

    return 0;
}
*/
