/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:45:15 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/06 14:53:45 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *str, int c)
{
	char	*cstr;

	cstr = (char *)str;
	while (*cstr != (char)c)
	{
		if (*cstr == '\0')
			return (NULL);
		cstr++;
	}
	return (cstr);
}
