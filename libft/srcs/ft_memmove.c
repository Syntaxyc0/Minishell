/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:44:27 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/07 14:49:44 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*csrc;
	unsigned char	*cdst;

	if (dst == NULL && src == NULL)
		return (NULL);
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	i = 0;
	if (cdst >= csrc)
	{
		while (size-- > 0)
			cdst[size] = csrc[size];
	}
	else
	{
		while (i < size)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}
