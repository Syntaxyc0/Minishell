/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:02:21 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/06 14:39:37 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t			i;
	unsigned char	*cptr1;
	unsigned char	*cptr2;

	i = 0;
	cptr1 = (unsigned char *)ptr1;
	cptr2 = (unsigned char *)ptr2;
	while (i < size)
	{
		if (cptr1[i] != cptr2[i])
			return (cptr1[i] - cptr2[i]);
		i++;
	}
	return (0);
}
