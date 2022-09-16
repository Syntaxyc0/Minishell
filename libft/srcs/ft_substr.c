/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:41:33 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/02 15:53:32 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *src, unsigned int start, size_t len)
{
	size_t			i;
	size_t			start_index;
	char			*ret;

	i = 0;
	ret = NULL;
	start_index = (size_t)start;
	if (src == NULL)
		return (NULL);
	if (start_index >= ft_strlen(src))
		return (ft_strdup(""));
	if (len > ft_strlen(src))
		len = ft_strlen(src);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (start_index < ft_strlen(src) && i < len)
	{
		ret[i] = src[start_index + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
