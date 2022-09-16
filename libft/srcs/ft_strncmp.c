/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:45:45 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/07 14:48:45 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*cstr1;
	unsigned char	*cstr2;

	i = 0;
	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	while (i < n)
	{
		if (cstr1[i] == '\0' && cstr2[i] == '\0')
			return (0);
		else if (cstr1[i] && cstr2[i] == '\0' )
			return (cstr1[i]);
		else if (cstr1[i] == '\0' && cstr2[i])
			return (-cstr2[i]);
		else if (cstr1[i] != cstr2[i])
			return (cstr1[i] - cstr2[i]);
		i++;
	}
	return (0);
}
