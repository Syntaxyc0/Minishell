/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:46:39 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/07 14:10:32 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	start = (void *)0;
	if (*f == NULL || lst == NULL)
		return (start);
	start = ft_lstnew((*f)(lst -> content));
	if (start == NULL)
		return (NULL);
	lst = lst -> next;
	while (lst)
	{
		new = ft_lstnew((*f)(lst -> content));
		if (new == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new);
		lst = lst -> next;
	}
	return (start);
}
