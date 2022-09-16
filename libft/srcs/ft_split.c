/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:42:56 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/08 12:31:20 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (*str == '\0')
		return (0);
	if (str[i] != c)
		count++;
	i++;
	while (str[i] != '\0')
	{
		if (str[i - 1] == c && str[i] != c)
			count++;
		i++;
	}
	return (count);
}

void	ft_cpy_word(char *dst, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	**ft_free_tab(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char	**ft_fill_tab(char **ret, const char *str, char c)
{
	int	i;
	int	len_word;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			len_word = 0;
			while (str[i + len_word] != c && str[i + len_word] != '\0')
				len_word++;
			ret[word] = (char *)malloc((len_word + 1) * sizeof(char));
			if (ret[word] == NULL)
				return (ft_free_tab(ret, word));
			ft_cpy_word(ret[word], str + i, c);
			i += len_word;
			word++;
		}
	}
	return (ret);
}

char	**ft_split(const char *str, char c)
{
	char	**ret;
	int		nb_words;

	if (str == NULL)
		return (NULL);
	nb_words = ft_count_words(str, c);
	ret = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret[nb_words] = NULL;
	ret = ft_fill_tab(ret, str, c);
	return (ret);
}
