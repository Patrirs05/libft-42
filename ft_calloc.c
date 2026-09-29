/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrirod <patrirod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:54:11 by marvin            #+#    #+#             */
/*   Updated: 2026/09/29 10:51:05 by patrirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function allocates memory for an array of nmemb elements of 
//size bytes each and returns
//a pointer to the allocated memory. The memory is set to zero. 
//If nmemb or size is 0,
//then calloc() returns either NULL, or a unique pointer value that
//can later be successfully passed to free().
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	array = (void *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}
