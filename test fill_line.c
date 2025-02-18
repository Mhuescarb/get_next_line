
static char *_fill_line_buffer(int fd, char *left_c, char *buffer)
{
    ssize_t b_read;
    char *tmp;
	b_read = 1;

    while (b_read > 0)
    {
        b_read = read(fd, buffer, BUFFER_SIZE);
        if (b_read == -1)
        {
            free(left_c);
            return (NULL);  // Mejor usar NULL en vez de 0
        }

        if (b_read == 0)  // No hay más datos para leer
            break;

        buffer[b_read] = '\0';  // Terminar la cadena con un '\0'

        if (!left_c)  // Si left_c es NULL, inicialízalo como cadena vacía
            left_c = ft_strdup("");

        tmp = left_c;  // Guardamos el valor original de left_c
        left_c = ft_strjoin(tmp, buffer);  // Concatenamos lo nuevo a left_c
        free(tmp);  // Liberamos el puntero temporal

        if (ft_strchr(buffer, '\n'))  // Si encontramos un salto de línea, salimos
            break;
    }
    return (left_c);  // Retornamos el buffer actualizado
}
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"  // Incluye el encabezado donde está tu función

#define BUFFER_SIZE 32  // Puedes ajustar este tamaño si lo deseas

// Prototipo de la función que vamos a probar
static char *_fill_line_buffer(int fd, char *left_c, char *buffer);

int main()
{
    int fd;
    char *left_c = NULL;
    char buffer[BUFFER_SIZE + 1];  // Buffer para almacenar los datos leídos
    char *line;

    // Abre el archivo de prueba
    fd = open("test.txt", O_RDONLY);  // Asegúrate de tener el archivo test.txt
    if (fd == -1)
    {
        perror("Error abriendo el archivo");
        return 1;
    }

    // Llamada a la función _fill_line_buffer para leer el archivo
    while ((line = _fill_line_buffer(fd, left_c, buffer)) != NULL)
    {
        // Imprime el contenido leído
        printf("%s", line);

        // Si se encuentra un salto de línea, limpiamos left_c
        if (ft_strchr(line, '\n'))  // Si hay un salto de línea, se limpia
        {
            free(left_c);
            left_c = NULL;
        }
    }

    // Cierra el archivo
    close(fd);

    // Libera cualquier memoria residual
    free(left_c);

    return 0;
}
