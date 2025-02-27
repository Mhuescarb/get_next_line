#include "get_next_line.h"
 
char *get_next_line(int fd)
{
    static char *left_ch;
    char *line;
    char *buffer;

    // Verificar condiciones de error iniciales
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(left_ch);
        left_ch = NULL;
        return (NULL);  // Si hay un error con fd o BUFFER_SIZE, retornar NULL
    }

    // Asignar buffer para leer los datos
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)  // Si no se pudo asignar memoria
        return (NULL);

    // Llenar la línea con datos leídos
    line = fill_line_buffer(fd, left_ch, buffer);
    free(buffer);  // Liberar buffer una vez que ya no se necesita
    buffer = NULL;

    if (!line)  // Si no se pudo obtener la línea
        return (NULL);

    // Guardar lo que queda de la línea para la siguiente llamada
    left_ch = set_line(line);

    return (line);  // Retornar la línea obtenida
}
