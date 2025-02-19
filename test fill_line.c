#include "get_next_line.h"

static char	*_fill_line_buffer(int fd, char *left_ch, char *buffer)
{
	ssize_t	b_read;
	char	*temp;

	b_read = 1;
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
	}
	if (b_read == 0)
		return (left_ch);
	return (left_ch);
}
