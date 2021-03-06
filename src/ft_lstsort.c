/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 12:53:14 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:31 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(int sort_type, t_list **lst, int (*cmp)(void*, void*))
{
	if (sort_type == BUBBLE_SORT)
		ft_bubblesort(lst, cmp);
}
