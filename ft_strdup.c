/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 20:23:54 by marvin            #+#    #+#             */
/*   Updated: 2026/09/27 20:23:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

\\function returns a pointer to a new string which is a duplicate of the string s.
\\Memory for the new string is obtained with malloc(3), and can be freed with free(3).
char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i <= len)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
