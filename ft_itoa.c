/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrirod <patrirod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:03:49 by patrirod          #+#    #+#             */
/*   Updated: 2026/09/29 11:59:05 by patrirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long nbr)
{
	size_t	cont;

	cont = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		cont++;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		cont++;
	}
	return (cont);
}

//Allocates memory and returns a string representing the value of the integer
//received as an argument. It must be able to handle negative numbers.
char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	i;
	size_t	len;

	nbr = n;
	len = ft_intlen(nbr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
