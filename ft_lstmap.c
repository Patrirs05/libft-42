/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 08:57:13 by marvin            #+#    #+#             */
/*   Updated: 2026/09/30 08:57:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Iterate over the list ‘lst’ and apply the function ‘f’ to the
//content of each node. Create a resulting list by successively applying the
//function ‘f’ to each node. The function ‘del’ is used to delete the content
//of a node if necessary.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*node_new;
	void 	*content_new;

	if (!lst || !f || !del)
		return (NULL);
	lst_new = NULL;
	while (lst != NULL)
	{
		content_new = f(lst->content);
		node_new = ft_lstnew(content_new);
		if (node_new == NULL)
		{
			del(content_new);
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, node_new);
		lst = lst->next;
	}
	return (lst_new);
}
