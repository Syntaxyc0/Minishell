/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:34:16 by gregoiregob       #+#    #+#             */
/*   Updated: 2022/09/26 12:36:24 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_big(char *a, char *b)
{
	if (ft_strlen(a) > ft_strlen(b))
		return (ft_strlen(a));
	else
		return(ft_strlen(b));
}

void	lst_del_unset(t_env *tmp, t_env *previous)
{
	if (tmp->key)
		free(tmp->key);
	if (tmp->value)
		free(tmp->value);
	if
		previous->next = tmp->next;
	free(tmp);
}

void	unset(t_mini *mini, int ac, char **av)
{
	int		i;
	t_env	*tmp;
	t_env	*previous;

	i = 1;
	tmp = mini->myenv;
	previous = 0;
	printf("ac = %d\n", ac);
	if (!ac)
		write_error_message("not enough arguments");
	while (ac--)
	{
		while (tmp)
		{
			if (ft_strncmp(av[i], tmp->key, str_big(av[i], tmp->key)) != 0)
			{
				previous = tmp;
				tmp = tmp->next;
			}
			else
			{
				printf("ENTER now_____________________________________\n");
				lst_del_unset(tmp, previous);
			}
		}
		i++;
	}
}
