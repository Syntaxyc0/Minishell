/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:24:28 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/20 10:38:23 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in_charset(char c, const char *charset)
{
	int	i;

	i = 0;
	if (*charset == '\0')
		return (0);
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_index_first_trim(const char *str, const char *charset)
{
	size_t	i;

	if (*str == '\0' || *charset == '\0')
		return (0);
	i = 0;
	while (ft_is_in_charset(str[i], charset))
		i++;
	return (i);
}

size_t	ft_index_last_trim(const char *str, const char *charset)
{
	size_t	len_str;

	if (*str == '\0')
		return (0);
	if (*charset == '\0')
		return (ft_strlen(str));
	len_str = ft_strlen(str);
	while (ft_is_in_charset(str[len_str - 1], charset) == 1 && len_str > 1)
		len_str--;
	return (len_str);
}

char	*ft_strtrim(const char *str, const char *charset)
{
	size_t	start_index;
	size_t	end_index;
	char	*result;

	if (str == NULL || charset == NULL)
		return (NULL);
	start_index = ft_index_first_trim(str, charset);
	end_index = ft_index_last_trim(str, charset);
	if (start_index >= end_index)
		end_index = start_index;
	result = ft_substr(str, start_index, end_index - start_index);
	return (result);
}
