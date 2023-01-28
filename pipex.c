/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:30:42 by adadoun           #+#    #+#             */
/*   Updated: 2023/01/25 06:30:48 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	id[2];

	if (argc != 5)
		ft_error("Enter a valid number of argument");
	if (pipe(fd) == -1)
		ft_error("pipe failed");
	id[0] = fork();
	if (id[0] < 0)
		ft_error("Fork failed");
	else if (id[0] == 0)
		child1(fd, argv, env);
	id[1] = fork();
	if (id[1] < 0)
		ft_error("Fork failed");
	else if (id[1] == 0)
		child2(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
