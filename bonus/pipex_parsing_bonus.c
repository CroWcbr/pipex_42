/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crow <crow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:24:31 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/24 21:20:37 by crow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**find_path(char **envr)
{
	char	**path;
	int		i;

	path = ((void *)0);
	i = -1;
	while (envr[++i])
	{
		if (ft_strnstr(envr[i], "PATH=", ft_strlen(envr[i])))
		{
			path = ft_split(envr[i] + ft_strlen("PATH="), ':');
			break ;
		}
	}
	if (!envr[i])
		ps_error("Error: no path in envr");
	if (!path)
		ps_error("Error: malloc error (path split)");
	return (path);
}

static char	*find_check_cmd(char **path, char *tmp_cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], tmp_cmd);
		if (!tmp)
			ps_error("Error: malloc error (tmp strjoin)");
		if (access(tmp, F_OK) == 0)
			return (tmp);
		else
			free(tmp);
	}
	return ((void *)0);
}

static char	**find_cmd(char *cmd_string, char **envr)
{
	char	**path;
	char	**cmd;
	char	*tmp_cmd;
	char	*tmp;

	path = find_path(envr);
	cmd = ft_split(cmd_string, ' ');
	if (!cmd)
		ps_error("Error: malloc error (cmd split)");
	tmp_cmd = ft_strjoin("/", *cmd);
	if (!tmp_cmd)
		ps_error("Error: malloc error (tmp_cmd strjoin)");
	tmp = *cmd;
	*cmd = find_check_cmd(path, tmp_cmd);
	if (!(*cmd))
		ps_error("Error: no access cmd");
	free(tmp);
	free(tmp_cmd);
	ft_free_split(path);
	return (cmd);
}

void	check_limiter_file(t_pipex *pip, int argc)
{
	if (ft_strnstr(pip->argv[1], "here_doc", ft_strlen("here_doc")))
	{
		pip->limiter = pip->argv[2];
		pip->l = 1;
		pip->file1 = 0;
		pip->file2 = open(pip->argv[argc - 1], \
					O_WRONLY | O_APPEND | O_CREAT, 0777);
		if (pip->file2 < 0)
			ps_error("Error: cannot open/create file2");
		pip->n_cmd = argc - 1 - 3;
	}
	else
	{
		pip->limiter = ((void *)0);
		if (access(pip->argv[1], F_OK) == -1)
			ps_error("Error: there is no file1");
		pip->file1 = open(pip->argv[1], O_RDONLY);
		if (pip->file1 < 0)
			ps_error("Error: cannot open file1");
		pip->file2 = open(pip->argv[argc - 1], \
					O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (pip->file2 < 0)
			ps_error("Error: cannot open/create file2");
		pip->n_cmd = argc - 1 - 2;
	}
}

t_pipex	*pipex_parsing(char **argv, int argc, char **envr)
{
	t_pipex	*pip;
	int		i;

	pip = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pip)
		ps_error("Error: malloc error create struct");
	pip->argv = argv;
	if (argc < 5 || (argc < 6 && \
		ft_strnstr(pip->argv[1], "here_doc", ft_strlen("here_doc"))))
		ps_error("Error: not enaugh argument parameters");
	pip->l = 0;
	check_limiter_file(pip, argc);
	pip->cmd = (char ***)malloc(sizeof(char **) * (pip->n_cmd + 1 + pip->l));
	if (!pip->cmd)
		ps_error("Error: malloc error massive cmd");
	pip->cmd[pip->n_cmd + pip->l] = ((void *)0);
	if (pip->l)
		pip->cmd[0] = ((void *)0);
	i = -1;
	while (++i < pip->n_cmd)
		pip->cmd[i + pip->l] = \
				find_cmd(pip->argv[argc - 1 - pip->n_cmd + i], envr);
	return (pip);
}
