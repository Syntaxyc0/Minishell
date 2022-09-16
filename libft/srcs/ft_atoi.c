/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbesnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:15:44 by jbesnier          #+#    #+#             */
/*   Updated: 2021/12/07 14:33:42 by jbesnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	atoi;
	int	is_negative;

	i = 0;
	atoi = 0;
	is_negative = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == ' ' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		atoi = atoi * 10 + str[i] - 48;
		i++;
	}
	if (is_negative == 1)
		return (-1 * atoi);
	return (atoi);
}
