/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:42:27 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/07 12:13:54 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elemcount, size_t elemsize)
{
	void	*tab;

	tab = NULL;
	tab = malloc(elemcount * elemsize);
	if (tab == NULL)
		return (tab);
	ft_memset(tab, 0, elemcount * elemsize);
	return (tab);
}
