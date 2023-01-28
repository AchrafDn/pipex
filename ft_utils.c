/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:24:36 by adadoun           #+#    #+#             */
/*   Updated: 2023/01/27 05:25:22 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error1(int *fd, int id, char *str)
{
	close(id);
	close(fd[0]);
	close(fd[1]);
	perror(str);
	exit(1);
}

void	pipe_free(char **ptr, char **str)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free (ptr);
	i = -1;
	while (str[++i])
		free(str[i]);
	free (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
