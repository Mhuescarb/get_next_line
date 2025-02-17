# get_next_line
get_next_line:
Es la función principal que se invoca para leer una línea de un archivo.

Inicialización:

Se declara un buffer dinámico (buffer) que se usará para leer datos desde el archivo.
Se verifica que el descriptor de archivo (fd) sea válido, que el tamaño del buffer sea positivo y que la operación de lectura se pueda realizar correctamente.
Chequeo de errores:

Si alguna de las condiciones falla (por ejemplo, fd es inválido, el BUFFER_SIZE es menor o igual a cero, o hay un error al leer el archivo), la función libera cualquier memoria previamente asignada y retorna NULL.
Lectura de datos:

Si no hay errores, se invoca la función _fill_line_buffer para intentar llenar el buffer y leer los datos hasta que encuentre un salto de línea (\n) o se haya leído todo el archivo.
Liberación de memoria:

Después de llenar el buffer, la memoria asignada a buffer se libera porque no se usará más en esta función.
Procesamiento de la línea:

Se pasa el contenido leído a la función _set_line, que corta la línea y guarda el resto para futuras lecturas.
Devolver la línea:

Si se ha leído una línea válida, se retorna, y se almacena cualquier carácter restante en left_c para la próxima llamada a get_next_line.
_set_line:
Esta función se encarga de procesar la cadena leída y separar la línea de texto del "resto" que queda para futuras lecturas.

Encontrar el final de la línea:

Recorre la cadena buscando el salto de línea (\n) o el final de la cadena (\0).
Si no encuentra un salto de línea, significa que la línea está completa y no hay más líneas por leer, por lo que retorna NULL.
Separar el resto de la línea:

Si encuentra un salto de línea, extrae la subcadena que contiene lo que queda después del salto de línea para usarlo en la próxima llamada a get_next_line.
Retornar lo que queda:

Si hay contenido después del salto de línea, se retorna una nueva cadena que contiene el "resto" para la próxima lectura. Si no queda nada, libera la memoria y lo pone como NULL.
_fill_line_buffer:
Esta función es responsable de llenar el buffer y manejar la lectura del archivo, leyendo datos en bloques de tamaño BUFFER_SIZE hasta que se encuentre un salto de línea o se haya leído todo el archivo.

Lectura del archivo:

Usa read() para leer los datos del archivo en bloques del tamaño de BUFFER_SIZE.
Si ocurre un error durante la lectura, se libera la memoria de left_c y se retorna NULL.
Construcción de la cadena:

Si se ha leído algo, la función verifica si hay un salto de línea en los datos leídos. Si lo hay, la lectura se detiene. Si no, sigue leyendo más datos.
El contenido del buffer se añade a left_c, que es la variable que acumula todos los caracteres leídos hasta que se obtiene una línea completa.
Retorno:

Devuelve la cadena que contiene los datos leídos hasta que se encuentra un salto de línea (\n) o se ha llegado al final del archivo.
_ft_strchr:
Esta función busca un carácter (c) en una cadena (s) y devuelve un puntero a la primera aparición de ese carácter.

Búsqueda:

Recorre la cadena s buscando el carácter c. Si lo encuentra, retorna la dirección de la primera aparición de ese carácter.
Si no lo encuentra:

Retorna NULL.
