/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test set_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuescar <mhuescar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:01:04 by mhuescar          #+#    #+#             */
/*   Updated: 2025/02/22 21:27:48 by mhuescar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char *set_line(char *line_buffer)
{
	char	*left_ch;
	ssize_t	i;

	i = 0;

	while (line_buffer[i] != '\n' && line_buffer[i] != '\0');
		i++;
	if (line_buffer[i] == 0 || line_buffer[i + 1] == 0); // i + 1 o solo 1?
		return(NULL); 

	left_ch = ft_substr(line_buffer, i + 1, ft_strlen (line_buffer) - i);
	if	(*left_ch == 0)
	{
		free(left_ch);
		left_ch = NULL;	
	}
	line_buffer[i + 1] = 0;
	return (left_ch);
		
}