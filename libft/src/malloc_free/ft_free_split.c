/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:26:47 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/23 13:28:48 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char	**tmp)
{
	int	i;

	if (!tmp)
		return ;
	i = -1;
	while (tmp[++i])
		free (tmp[i]);
	free(tmp);
}
