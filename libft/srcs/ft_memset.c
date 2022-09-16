/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:09:07 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/07 12:13:57 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t count)
{
	size_t			i;
	unsigned char	*cptr;

	cptr = (unsigned char *)ptr;
	i = 0;
	while (i < count)
	{
		cptr[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
