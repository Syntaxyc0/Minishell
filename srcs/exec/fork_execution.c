/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:50:41 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/21 16:18:55 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int dup_io(t_command *cmd)
{
	if (cmd->io > 0)
	{
		if (dup2(cmd->fd[0], STDIN_FILENO) == -1)
			{
				g_exit_status = 1;
				perror(NULL);
				return (-1);
			}
	}
	if (cmd->io == -1 || cmd->io == 3)
	{
		if (dup2(cmd->fd[1], STDOUT_FILENO) == -1)	
		{
			g_exit_status = 1;
			perror(NULL);
			return (-1); 
		}
	}
	if (cmd->io == 2 || cmd->io == -2)
	{
		if (dup2(cmd->next->fd[1], STDOUT_FILENO) == -1)	
		{
			g_exit_status = 1;
			perror(NULL);
			return (-1); 
		}
	}
	return (0);
}

int	ft_close_all(t_mini *mini)
{
	t_command *cmd;

	cmd = mini->commands;
	while (cmd)	
	{
		if (cmd->fd[0])
		{
			if (close(cmd->fd[0]) == -1)
			{
				g_exit_status = 1;
				perror(NULL);
			}
		}
		if (cmd->fd[1])
		{
			if (close(cmd->fd[1]) == -1)
			{
				g_exit_status = 1;
				perror(NULL);
			}
		}
		cmd = cmd->next;
	}
	return (0);
}

int	ft_access(t_command *cmd, t_mini *mini)
{
	int		i;
	char	*tmp;
	char	*path;

	i = -1;
	while (mini->all_path[++i])
	{
		tmp = ft_strjoin(mini->all_path[i], "/");
		path = ft_strjoin(tmp, cmd->args[0]);
		free(tmp);
		if (access(path, X_OK) == 0)
		{
				cmd->fullpath = path;
				return (0);
		}
		free(path);
	}
	if (access(cmd->args[0], X_OK) == 0)
		return (0);
	if (!mini->all_path[i])
	{
		error_redisplay_line(cmd->args[0], ": command not found\n", 127);
		return (-1);
	}
	return (0);
}

void	execution(t_command *cmd, t_mini *mini)
{
	//dup2 in _ out
	if (dup_io(cmd) == -1)
		exit(g_exit_status) ;
	//close all fd
	if (ft_close_all(mini) == -1)
		exit(g_exit_status) ;
	//access
	if (ft_access(cmd, mini) == -1)
		exit(g_exit_status) ;
	//execve (!!!WARNING mini->environment n'est plus valide si une modif de l'env est effectue)
	if (execve(cmd->fullpath, cmd->args, mini->environment) == -1)
	{
		perror(NULL);
		exit(g_exit_status);
	}
}