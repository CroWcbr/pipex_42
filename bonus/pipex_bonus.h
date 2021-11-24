/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:14:39 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/24 13:27:05 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/include/libft.h"

typedef struct s_pipex
{
	char	**argv;
	char	*limiter;
	int		l;
	int		file1;
	int		file2;
	int		n_cmd;
	char	***cmd;
	int		*fd;
	int		*pid;
	int		*status;
}t_pipex;

//parsing
t_pipex	*pipex_parsing(char **argv, int argc, char **envr);
void	parrent_process(t_pipex *pip);

//utils
void	ps_error(char *str);
void	free_split(char	**tmp);

#endif
