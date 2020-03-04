/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:41:19 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:52:00 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	while (*s1 && *s2 && *s1 == *s2 && len--)
	{
		s1++;
		s2++;
	}
	return ((len == 0) ? 0 : (unsigned char)*s1 - *s2);
}
