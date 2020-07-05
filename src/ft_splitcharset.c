/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcharset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:37:13 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/05 12:52:51 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static size_t	ft_getwords(char *s, char *c)
{
	size_t	n;

	n = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && ft_strchr(c, *s))
			s++;
		if (*s && !ft_strchr(c, *s))
		{
			n++;
			while (*s && !ft_strchr(c, *s))
				s++;
		}
	}
	return ((n == 0) ? 1 : n);
}

char			**ft_splitcharset(const char *str, const char *charset)
{
	char	**first;
	char	**ret;
	char	*anchor;
	int		words;

	words = ft_getwords((char *)str, (char *)charset);
	if (!(ret = ft_calloc(sizeof(char *), words + 1)))
		return (NULL);
	first = ret;
	anchor = (char *)str;
	while (*str)
		while (ft_strchr(charset, (int)*str++))
		{
			if (str - anchor - 1 > 1 && words > 0)
			{
				if (!(*ret = ft_strldup(anchor, (str - anchor - 1))))
					return (NULL);
				if (--words > 0)
					ret++;
			}
			anchor = (char *)(str);
		}
	if (words > 0 && !(*ret = ft_strldup(anchor, (str - anchor))))
		return (NULL);
	return (first);
}
