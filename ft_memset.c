/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrirod <patrirod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:40:17 by patrirod          #+#    #+#             */
/*   Updated: 2026/09/24 12:41:11 by patrirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//se utiliza para rellenar un bloque de memoria 
//con un valor constante específico
//debe llenar un bloque de memoria byte por byte
//La memoria que recibe puede tener basura o cualquier dato, 
//por lo que buscar un '\0' hará que la función se detenga antes 
//de tiempo o intente leer memoria prohibida. 
//Solo debes guiarte por el límite n.
void	*memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
