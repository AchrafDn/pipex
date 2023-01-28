/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:30:09 by adadoun           #+#    #+#             */
/*   Updated: 2023/01/25 06:30:11 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *f, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((f[i] || s[i]) && i < n)
	{
		if (f[i] == s[i])
			i++;
		else
			return ((unsigned char)f[i] - (unsigned char)s[i]);
	}
	return (0);
}
