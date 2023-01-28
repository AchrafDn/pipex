/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:51:54 by adadoun           #+#    #+#             */
/*   Updated: 2023/01/27 05:25:58 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>

void	child1(int *fd, char **argv, char **env);
void	child2(int *fd, char **argv, char **env);
int		ft_strncmp(const char *f, const char *s, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	pipe_free(char **ptr, char **str);
void	ft_error1(int *fd, int id, char *str);

#endif
