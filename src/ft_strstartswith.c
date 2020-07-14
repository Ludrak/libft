/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartswith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:39:52 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:58 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstartswith(const char *str, const char *prefix)
{
	size_t	len_str;
	size_t	len_prefix;

	len_str = ft_strlen(str);
	len_prefix = ft_strlen(prefix);
	if (len_prefix > len_str)
		return (0);
	return (ft_strncmp(str, prefix, len_prefix) == 0);
}
