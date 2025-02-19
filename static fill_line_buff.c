#include "get_next_line.h"

static	char	*fill_line_buff(int fd, char *left_ch, char *buffer)
{
	ssize_t	b_read;
	int		line_break;
	char	*temp;

	b_read = 1;
	line_break = 0;
	if (fd < 0 || !buffer)
	{
		return (NULL);
	}
	while (b_read > 0 && !line_break)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_ch);
			return (NULL);
		}
		buffer[b_read] = '\0';
		if (!left_ch)
			left_ch = ft_strdup (buffer);
		else
		{
			temp = ft_strjoin(left_ch, buffer);
			free(left_ch);
			left_ch = temp;
		}
		if (ft_strchr(buffer, '\n'))
			line_break = 1;
	}
	return (left_ch);
}

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

#define BUFFER_SIZE 32  // Puedes ajustar el tamaño del buffer

// Prototipo de la función que vamos a probar
static char *fill_line_buff(int fd, char *left_ch, char *buffer);

int main()
{
    int fd;
    char *left_ch = NULL;
    char buffer[BUFFER_SIZE + 1];  // Buffer para almacenar datos leídos
    char *result;

    // Abre el archivo de prueba
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error abriendo el archivo");
        return 1;
    }

    // Llamada a la función fill_line_buff para leer del archivo
    while ((result = fill_line_buff(fd, left_ch, buffer)) != NULL)
    {
        // Imprime el resultado obtenido (el contenido leído hasta el salto de línea)
        printf("%s", result);
        free(result);  // Libera el buffer que se ha devuelto
    }

    // Cierra el archivo
    close(fd);

    return 0;
}
