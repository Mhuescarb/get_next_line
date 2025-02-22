/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuescar <mhuescar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:20:37 by mhuescar          #+#    #+#             */
/*   Updated: 2025/02/22 21:25:34 by mhuescar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h> //strchr
# include <stdlib.h> // malloc
# include <string.h> //strlen

char		*get_next_line(int fd);

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
const char	*ft_strchr(const char *s, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strjoin(char *s1, char*s2);

#endif
