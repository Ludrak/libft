/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:07:10 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:45:30 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*next;
	int		len;

	len = 0;
	next = lst;
	while (next)
	{
		next = next->next;
		len++;
	}
	return (len);
}
