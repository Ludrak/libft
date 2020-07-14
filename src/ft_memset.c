/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:02:47 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:36 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str + n;
	while (n > 0)
	{
		n--;
		tmp--;
		*tmp = c;
	}
	return (str);
}
