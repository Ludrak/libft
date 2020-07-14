/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendwith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:33:09 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:48 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strendwith(const char *str, const char *suffix)
{
	size_t	len_str;
	size_t	len_suffix;

	len_str = ft_strlen(str);
	len_suffix = ft_strlen(suffix);
	if (len_suffix > len_str)
		return (0);
	return (ft_strncmp(str + len_str - len_suffix, suffix, len_suffix) == 0);
}
