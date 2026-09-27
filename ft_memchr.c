/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:04:49 by marvin            #+#    #+#             */
/*   Updated: 2026/09/27 13:04:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

\\function scans the initial n bytes of the memory area pointed to by s for the first instance of c.
\\Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char	*)s;
	if (n == 0)
		return(NULL);
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
