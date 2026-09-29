/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrirod <patrirod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:21:18 by patrirod          #+#    #+#             */
/*   Updated: 2026/09/29 15:27:33 by patrirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Returns the last node of the list.
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
