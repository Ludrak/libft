/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:50:20 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/15 22:30:01 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int			ft_atoi_base(char *str, char *base)
{
	char			buf[256];
	int				i;
	int				sign;
	unsigned int	nb;

	ft_memset(buf, -1, 256);
	i = 0;
	while (base[i] && base[i] != '+' && base[i] != '-'
		&& !ft_isspace(base[i]) && buf[(unsigned char)base[i]] == -1)
	{
		buf[(unsigned char)base[i]] = i;
		i++;
	}
	if (base[i])
		return (0);
	sign = 1;
	while (*str == '-' || *str == '+' || ft_isspace(*str))
		if (*str++ == '-')
			sign *= -1;
	nb = 0;
	while (*str && buf[(unsigned char)*str] != -1)
		nb = (i * nb) + (buf[(unsigned char)*str++]);
	return (nb * sign);
}
