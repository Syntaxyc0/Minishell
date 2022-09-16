/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:15:52 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/06 10:16:16 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	sub_len;

	if (*sub == '\0')
		return ((char *)str);
	sub_len = ft_strlen(sub);
	while (*str != '\0' && (len-- >= sub_len))
	{
		if (*str == *sub && ft_strncmp(str, sub, sub_len) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
