/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:38:39 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:45 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_c;

	s_c = (char *)s;
	while (*s_c)
	{
		if (*s_c == (char)c)
			return (s_c);
		s_c++;
	}
	if (*s_c == (char)c)
		return (s_c);
	return (0);
}
