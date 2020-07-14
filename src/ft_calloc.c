/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:55:07 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:44:57 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		*ptr;

	if (!(ptr = malloc(nmemb * size)))
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
