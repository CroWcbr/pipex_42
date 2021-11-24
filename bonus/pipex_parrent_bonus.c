/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parrent_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:13:37 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/26 18:55:32 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	close_fd(t_pipex *pip)
{
	int	i;

	i = -1;
	while (++i < (pip->n_cmd - 1 + pip->l) * 2)
		close(pip->fd[i]);
	if (!pip->l)
		close(pip->file1);
	close(pip->file2);
}

static void	child(char **cmd, int fd_in, int fd_out, t_pipex *pip)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close_fd(pip);
	execve(cmd[0], cmd, NULL);
	ps_error("Error: execve mistake");
}

static void	child_stdin(int fd_in, int fd_out, t_pipex *pip)
{
	char	*line;
	int		r;

	while (1)
	{
		r = gnl(fd_in, &line);
		if ((r == 0 && !line) || r == -1)
			break ;
		if (ft_strnstr(pip->limiter, line, ft_strlen(pip->limiter)))
			break ;
		write(fd_out, line, ft_strlen(line));
		if (r != 0)
			write(fd_out, "\n", 1);
		free(line);
	}
	close_fd(pip);
	exit (0);
}

static void	child_process(t_pipex *pip)
{
	int	i;	

	i = -1;
	while (++i < pip->n_cmd + pip->l)
	{
		pip->pid[i] = fork();
		if (pip->pid[i] == -1)
			ps_error("Error: fork mistake");
		if (pip->pid[i] == 0)
		{
			if (i == 0 && pip->limiter)
				child_stdin(pip->file1, pip->fd[i * 2 + 1], pip);
			else if (i == 0)
				child(pip->cmd[i], pip->file1, pip->fd[i * 2 + 1], pip);
			else if (i == pip->n_cmd - 1 + pip->l)
				child(pip->cmd[i], pip->fd[2 * (i - 1)], pip->file2, pip);
			else
				child(pip->cmd[i], pip->fd[2 * (i - 1)], \
						pip->fd[i * 2 + 1], pip);
		}
	}
}

void	parrent_process(t_pipex *pip)
{
	int	i;
	int	status;

	i = -1;
	while (++i < pip->n_cmd - 1 + pip->l)
		if (pipe(pip->fd + i * 2) == -1)
			ps_error("Error: pipe mistake");
	child_process(pip);
	close_fd(pip);
	i = -1;
	status = 0;
	while (++i < pip->n_cmd + pip->l)
	{
		waitpid(pip->pid[i], &pip->status[i], 0);
		if (WEXITSTATUS(pip->status[i]) != 0)
			status = 1;
	}
	if (status)
		ps_error("Error: execve comand flag error");
}
