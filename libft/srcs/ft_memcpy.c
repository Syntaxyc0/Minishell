/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:38:50 by jbesnier          #+#    #+#             */
/*   Updated: 2021/11/26 11:39:28 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	i;
	char	*csource;
	char	*cdestination;

	i = 0;
	csource = (char *)source;
	cdestination = (char *)destination;
	if (csource == NULL && cdestination == NULL)
		return (NULL);
	while (i < size)
	{
		cdestination[i] = csource[i];
		i++;
	}
	return (destination);
}
