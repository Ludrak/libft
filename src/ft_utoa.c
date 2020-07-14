/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:29:03 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:46:03 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ucount(unsigned int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char			*result;
	int				i;
	unsigned int	nb;

	nb = n;
	i = ft_ucount(n);
	if (!(result = ft_calloc((ft_ucount(n) + 1), sizeof(*result))))
		return (0);
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (nb)
	{
		result[--i] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}
