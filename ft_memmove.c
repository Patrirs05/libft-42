/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrirod <patrirod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:16:12 by patrirod          #+#    #+#             */
/*   Updated: 2026/09/24 15:25:45 by patrirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// se compara la posición de los punteros dest y src
void	*memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;

	if (!dest && !src)
		return (NULL);
	ptr_src = (const unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	if (ptr_dest > ptr_src)
	{
		i = n;
		while (i-- > 0)
			ptr_dest[i] = ptr_src[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dest);
}
