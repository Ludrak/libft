/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:13:56 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:56 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	pos;

	pos = 0;
	if (!*little)
		return ((char *)big);
	while (big[pos] && pos < len)
	{
		i = 0;
		if (big[pos] == little[i])
		{
			while (little[i] && big[pos + i] == little[i] && pos + i < len)
				i++;
			if (!little[i])
				return ((char *)(big + pos));
		}
		pos++;
	}
	return (0);
}
