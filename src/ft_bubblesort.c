/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 12:54:28 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/14 13:44:54 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_lst(t_list **a, t_list **b)
{
	void	*tmp;

	tmp = (*a)->content;
	(*a)->content = (*b)->content;
	(*b)->content = tmp;
}

void		ft_bubblesort(t_list **alst, int (*cmp)(void*, void*))
{
	t_list	*first;
	int		sorted;

	sorted = 0;
	first = NULL;
	if (alst)
	{
		if (!(first = *alst))
			return ;
		while (!sorted)
		{
			sorted = 1;
			while ((*alst)->next)
			{
				if (cmp((*alst)->content, (*alst)->next->content)
					&& !(sorted = 0))
					swap_lst(alst, &(*alst)->next);
				*alst = (*alst)->next;
			}
			if (!sorted)
				*alst = first;
		}
	}
	*alst = first;
}
