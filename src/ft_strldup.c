/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 12:36:16 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:52 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *str, size_t len)
{
	char	*ret;
	size_t	len_s;
	int		i;

	i = -1;
	len_s = ft_strlen(str);
	if (!(ret = malloc((((len_s > len) ? len : len_s) + 1) * sizeof(*ret))))
		return (0);
	while (str[++i] && len--)
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}
