/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:52:21 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:46 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	i = -1;
	if (!(ret = malloc((ft_strlen(str) + 1) * sizeof(*ret))))
		return (0);
	while (str[++i])
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}
