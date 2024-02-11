/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_children.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:04:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/11 10:37:55 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void ft_execute_cmd(t_var *var, int *i_child);
static void	ft_first_child_helper(t_var *var, int *i_child);
static void	ft_helper_last_child(t_var *var, int *i_child);

void	ft_first_child(t_var *var, int *i_child)
{
	if (pipe(var->pipe_fd) < 0)
		ft_error(var, "error creating pipe", 0);
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] < 0)
		ft_error(var, "error creating process", 0);
	if (var->pid[*i_child] == 0)
		ft_first_child_helper(var, i_child);
	else
	{
		dup2(var->pipe_fd[0], STDIN_FILENO);
		close(var->pipe_fd[1]);
		close(var->pipe_fd[0]);
	}
}

void	ft_last_child(t_var *var, int *i_child)
{
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] < 0)
		ft_putstr_fd("error start child process", -1);
	if (var->pid[*i_child] == 0)
		ft_helper_last_child(var, i_child);
}

static void ft_execute_cmd(t_var *var, int *i_child)
{
	var->path_exe = ft_valid_exe(var, *i_child);
	if (!var->path_exe)
		ft_error(var, var->path_exe, 127);
	if (execve(var->path_exe, var->arg->cmd[*i_child], var->path) == -1)
		ft_error(var, var->path_exe, 127);
}

static void	ft_first_child_helper(t_var *var, int *i_child)
{
	var->infile = open(var->arg->file1, O_RDONLY);
	if (var->infile == -1)
		ft_error(var, var->arg->file1, 1);
	dup2(var->infile, STDIN_FILENO);
	dup2(var->pipe_fd[1], STDOUT_FILENO);
	close(var->pipe_fd[0]);
	close(var->pipe_fd[1]);
	close(var->infile);
	ft_execute_cmd(var, i_child);
}

static void	ft_helper_last_child(t_var *var, int *i_child)
{
	var->outfile = open(var->arg->file2, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (var->outfile == -1)
		ft_error(var, var->arg->file2, 1);
	dup2(var->outfile, STDOUT_FILENO);
	close(var->outfile);
	ft_execute_cmd(var, i_child);
}
