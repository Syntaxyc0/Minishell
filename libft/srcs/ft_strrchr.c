/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:33:48 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/06 14:54:14 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	*cstr;

	len = ft_strlen(str);
	cstr = (char *)str + len;
	while (cstr > str && *cstr != (char)c)
		cstr--;
	if (*cstr == (char) c)
		return (cstr);
	return (NULL);
}
