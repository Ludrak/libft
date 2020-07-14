/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:15:51 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:35 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned int	i;

	i = 0;
	tmp = (unsigned char *)dst;
	if (dst == src || !n)
		return (dst);
	while (i < (unsigned int)n)
	{
		*tmp = *(unsigned char *)(src + i);
		tmp++;
		i++;
	}
	return (dst);
}
