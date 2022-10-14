/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:02:20 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/14 10:29:14 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	k = 0;
	while (src[k] != '\0')
		k++;
	return (k + size);
}

/*Esta función concatena 2 strings hasta un límite de caracteres, coge el src y
 * lo copia a partir del final del dest, pero la longitud empieza al principio
 * del dest, es decir, va a contar los caracteres de dest, va a copiar los que 
 * falten para llegar al size - 1 y ese último caracter será el final de línea
 * 
 * La versión de Rau es muy diferente, tengo qe mirar su git si no funciona esta
 * */