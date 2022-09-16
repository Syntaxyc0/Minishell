/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:39:54 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/07 14:19:32 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *prefix, const char *suffix)
{
	size_t		i;
	size_t		len_prefix;
	size_t		len_suffix;
	char		*ret;

	i = 0;
	ret = NULL;
	if (!prefix || !suffix)
		return (NULL);
	len_prefix = ft_strlen(prefix);
	len_suffix = ft_strlen(suffix);
	ret = (char *)malloc(len_prefix + len_suffix + 1);
	if (ret == NULL)
		return (NULL);
	while (i < len_prefix + len_suffix)
	{
		if (i < len_prefix)
			ret[i] = prefix[i];
		else
			ret[i] = suffix[i - len_prefix];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
