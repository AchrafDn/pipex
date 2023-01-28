/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:27:25 by adadoun           #+#    #+#             */
/*   Updated: 2023/01/25 06:27:28 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	if (start >= slen)
		len = 0;
	else if ((start + len) > slen)
		len = slen - start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int	nword(const char *s, char c)
{
	int		nb;
	size_t	i;
	int		j;

	i = 0;
	nb = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
		{
			j++;
		}
		if (j != 0)
		{
			i = i + j;
			nb = nb + 1;
		}
		else
		i++;
	}
	return (nb);
}

static void	ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

static char	**ft_res(char **ptr, char *s, char c, int k)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j != 0)
		{
			ptr[k] = ft_substr(s, i, j);
			if (!ptr[k])
			{
				ft_free(ptr);
				return (NULL);
			}
			i = i + j;
			k++;
		}
		else
			i++;
	}
	ptr[k] = 0;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		nb;

	if (!s)
		return (NULL);
	nb = nword(s, c);
	ptr = malloc(sizeof(char *) * (nb + 1));
	if (!ptr)
		return (NULL);
	return (ft_res(ptr, (char *)s, c, 0));
}
