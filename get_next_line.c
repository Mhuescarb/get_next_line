/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuescar <mhuescar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:03:17 by mhuescar          #+#    #+#             */
/*   Updated: 2025/02/22 21:24:06 by mhuescar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line_buff(int fd, char *left_ch, char *buffer);
static char	*set_line(char *line_buff);
/*static char *ft_strchr(char *s, int c);*/

char	*get_next_line(int fd)
{
	static char	*left_ch;
	char	*line;
	char	buffer;
	
	buffer = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char)); //sizeof ?

}