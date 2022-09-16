/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:05:00 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/08 10:58:42 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_len(int nbr)
{
	int				len;
	unsigned int	cnbr;

	if (nbr == 0)
		return (1);
	len = 0;
	cnbr = nbr;
	if (nbr < 0)
	{
		cnbr = -cnbr;
		len++;
	}
	while (cnbr != 0)
	{
		cnbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char			*result;
	int				len;
	int				i;
	unsigned int	cnbr;

	len = nb_len(nbr);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	i = 0;
	cnbr = nbr;
	if (nbr < 0)
	{
		i++;
		result[0] = '-';
		cnbr = -nbr;
	}
	while (len-- > i)
	{
		result[len] = cnbr % 10 + '0';
		cnbr /= 10;
	}
	return (result);
}
