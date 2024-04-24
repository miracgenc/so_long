/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migenc <migenc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:26:25 by migenc            #+#    #+#             */
/*   Updated: 2024/04/21 14:26:26 by migenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*root;
	void	*cl;

	if (!lst || !f)
		return (NULL);
	root = NULL;
	while (lst)
	{
		cl = f(lst->content);
		if (!cl)
			return (ft_lstclear(&root, del), NULL);
		new = ft_lstnew(cl);
		if (!new)
			return (ft_lstclear(&root, del), del(cl), NULL);
		ft_lstadd_back(&root, new);
		lst = lst->next;
	}
	return (root);
}
