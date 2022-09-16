/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:31:49 by jbesnier          #+#    #+#             */
/*   Updated: 2021/11/26 14:24:06 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len_src;
	char	*cpy;

	i = 0;
	cpy = NULL;
	len_src = ft_strlen(src);
	cpy = malloc((len_src + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (i < len_src)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
