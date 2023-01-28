/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:26:42 by adadoun           #+#    #+#             */
/*   Updated: 2023/01/25 07:09:26 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*env_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			return (env[i]);
		i++;
	}
	perror("PATH");
	exit(1);
	return (NULL);
}

char	*check_access(char *str, char **env)
{
	char	**v_path;
	char	**split;
	char	*cmd_path;
	int		i;

	cmd_path = NULL;
	split = ft_split(str, ' ');
	if (access(split[0], X_OK) == 0)
		return (split[0]);
	else
	{
		v_path = ft_split(env_path(env) + 5, ':');
		i = -1;
		while (v_path[++i])
		{
			cmd_path = ft_strjoin(v_path[i], split[0]);
			if (access(cmd_path, X_OK) == 0)
				break ;
			free(cmd_path);
		}
	}
	pipe_free(v_path, split);
	return (cmd_path);
}

void	child2(int *fd, char **argv, char **env)
{
	int		id;
	char	*cmd_path;

	id = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (id < 0)
		ft_error1(fd, id, "Open 2 failed");
	if (argv[3][0] == '\0')
		ft_error1(fd, id, "Cmd 2 is empty");
	cmd_path = check_access(argv[3], env);
	if (cmd_path == NULL)
		ft_error1(fd, id, "Cmd 2 not found");
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(id, STDOUT_FILENO);
	execve(cmd_path, ft_split(argv[3], ' '), env);
	close(fd[0]);
	close(id);
	write(2, "execve 2 failed\n", 16);
	exit(1);
}

void	child1(int *fd, char **argv, char **env)
{
	int		id;
	char	*cmd_path;

	id = open(argv[1], O_RDONLY);
	if (id < 0)
		ft_error1(fd, id, "Open failed");
	if (argv[2][0] == '\0')
		ft_error1(fd, id, "Cmd 1 is empty");
	cmd_path = check_access(argv[2], env);
	if (cmd_path == NULL)
		ft_error1(fd, id, "Cmd 1 not found");
	close(fd[0]);
	dup2(id, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execve(cmd_path, ft_split(argv[2], ' '), env);
	perror("exec");
	close(fd[1]);
	close(id);
	exit(1);
}
