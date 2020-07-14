/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constrain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:45:15 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:18 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_constrain(int val, int min, int max)
{
	if (min > max)
		return (0);
	if (val > max)
		val = max;
	if (val < min)
		val = min;
	return (val);
}
