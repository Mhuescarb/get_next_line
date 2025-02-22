/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuescar <mhuescar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:15:53 by mhuescar          #+#    #+#             */
/*   Updated: 2025/02/22 20:59:06 by mhuescar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	ft_strlen (mide la longitud necesaria para ft_strdup)
	ft_strdup (para "hacer hueco" a la cadena de carcteres que se generará)
	ft_strchr (para buscar '\n')
	ft_strlcpy (necesaria para ft_strjoin)
	ft_strlcat(necesaria para ft_strjoin)
	ft_strjoin (para unir el contenido restante en buff a lo que está en left_ch)
*/
size_t ft_strlen(const char *s)
{
	size_t	i;
	i = 0;
	
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	dest = (char *) malloc (ft_strlen(s1) + 1); 
	if (!dest || dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1 [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
const char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ch;
	
	ch = (char) c; // cast de int a char para incluir chars de más de un byte
	i = 0;

	while (s[i])
	{

		if (s[i] == ch)
			return &s[i]; // no se castea el puntero pq es const char
		i++;
	}
	if (s[i] == ch)
		return &s[i];
		
return (NULL);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src [i] != '\0' && i < (size -1))
	{
		dst[i] = src [i];
		i++;
	}
	dst [i] = '\0';
	return (ft_strlen(src));
}
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	
	d = 0;
	s = 0;
	
	while (dst [d] && d < size)
		d++;
	while (src [s]&& (s + d + 1) < size)
	{
		dst [s + d] = src [s];
		s++;
	}
	if (d < size)
			dst [s + d] = '\0';
	return (d + ft_strlen (src));
}
char	*ft_strjoin(char *s1, char*s2)
{
	char	*result;
	size_t 	text1;
	size_t	text2;

	if (!s1 || !s2)
		return (NULL);
		
	text1 = ft_strlen(s1); //se mide y se guarda en *s1
	text2 = ft_strlen(s2);
	
	result = (char *) malloc (text1 + text2 +1); // asignamos memoria para result
	
	if (!result)
		return (NULL);
	ft_strlcpy (result, s1, text1 + 1);
	ft_strlcat (result, s2, text1 + text2 +1);

return (result);

}
char	*ft_substr (char *sub, unsigned int start, size_t lenght)
{
	ssize_t	i;
	char	*str;
	
	if(!sub)
		return(NULL);
	if (start > ft_strlen(sub))
		return (malloc (1));
	if (lenght > ft_strlen (sub + start))
		lenght = ft_strlen (sub + start);
	str = malloc ((lenght + 1) *sizeof(char));
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