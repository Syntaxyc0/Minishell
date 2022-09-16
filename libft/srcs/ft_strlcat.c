/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:47:30 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/06 14:26:02 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	len_dst;

	j = 0;
	len_dst = ft_strlen(dst);
	if (size <= len_dst || size == 0)
		return (size + ft_strlen(src));
	while (len_dst < size - 1 && src[j])
	{
		dst[len_dst] = src[j];
		len_dst++;
		j++;
	}
	dst[len_dst] = '\0';
	while (src[j])
	{
		j++;
		len_dst++;
	}
	return (len_dst);
}
