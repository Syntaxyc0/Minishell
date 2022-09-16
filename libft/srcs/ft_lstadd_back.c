/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:41:58 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/07 13:38:06 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		last -> next = new;
	}
}
