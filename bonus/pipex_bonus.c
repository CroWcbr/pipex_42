/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:25:55 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/26 18:39:58 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ps_error(char *str)
{
//	write(2, str, 5);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit (0);
}

static void	pipex_add_init(t_pipex *pip)
{
	pip->fd = (int *)malloc(sizeof(int) * (pip->n_cmd - 1 + pip->l) * 2);
	if (!pip->fd)
		ps_error("Error: malloc error (init fd)");
	pip->pid = (int *)malloc(sizeof(int) * (pip->n_cmd + pip->l));
	if (!pip->pid)
		ps_error("Error: malloc error (init pid)");
	pip->status = (int *)malloc(sizeof(int) * (pip->n_cmd + pip->l));
	if (!pip->status)
		ps_error("Error: malloc error (init status)");
}

int	main(int argc, char *argv[], char *envr[])
{
	t_pipex	*pip;
	int		i;

	pip = pipex_parsing(argv, argc, envr);
	pipex_add_init(pip);
	parrent_process(pip);
	i = -1;
	while (++i < pip->n_cmd + pip->l)
		ft_free_split(pip->cmd[i]);
	free(pip->cmd);
	free(pip->fd);
	free(pip->pid);
	free(pip->status);
	free(pip);
	return (0);
}
