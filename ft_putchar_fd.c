/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrirod <patrirod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:37:18 by patrirod          #+#    #+#             */
/*   Updated: 2026/09/29 12:44:31 by patrirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Sends the character ‘c’ to the specified file descriptor.
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
