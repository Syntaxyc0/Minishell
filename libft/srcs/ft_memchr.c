/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:43:50 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/06 14:53:31 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int c, size_t size)
{
	char	*cmem;
	size_t	i;

	i = 0;
	cmem = (void *)mem;
	while (i < size)
	{
		if (cmem[i] == (char)c)
			return ((cmem + i));
		i++;
	}
	return (NULL);
}
