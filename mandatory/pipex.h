/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:14:39 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/24 13:27:10 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/include/libft.h"

typedef struct s_pipex
{
	char	**argv;
	int		fd[2];
	int		file1;
	int		file2;
	char	**cmd1;
	char	**cmd2;
}t_pipex;

void	pipex_parsing(t_pipex *pip, char **envr);
void	ps_error(char *str);

#endif
