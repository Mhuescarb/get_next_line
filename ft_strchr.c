/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuescar <mhuescar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:08:23 by mhuescar          #+#    #+#             */
/*   Updated: 2025/02/23 19:14:01 by mhuescar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char *ft_strchr(char *s, int c)
{
    unsigned int i;
    char ch;

    ch = (char) c; // Se utiliza int y se castea para que admita valores como ñ.
    i = 0;
    while (s[i])  // Bucle que recorre la cadena
    {
        if (s[i] == ch)  // Si el carácter actual es igual al que buscamos
            return ((char *) &s[i]);  // Retorna la dirección de la posición encontrada
        i++;  // Avanza al siguiente carácter
    }
    if (s[i] == ch)  // Después del bucle, verifica si el carácter buscado es el '\0' final
        return ((char *) &s[i]);  // Si el carácter es '\0', lo encontramos y lo retornamos
    return (NULL);  // Si no se encuentra, devuelve NULL
} */
