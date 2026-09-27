# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlcpy                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/25 13:21:14 by marvin            #+#    #+#              #
#    Updated: 2026/09/25 13:21:14 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	} 
	dst[i] = '\0';
	return (len);
}
