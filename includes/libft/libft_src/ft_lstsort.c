/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 03:41:12 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/01 21:48:10 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **lst, int (*cmp)(int, int))
{
	t_list	*hold;
	t_list	*scout;
	t_list	*trail;

	scout = *lst;
	while (scout->next)
	{
		hold = scout;
		scout = scout->next;
		if (*lst == hold && !cmp(hold->data, scout->data))
		{
			*lst = hold->next;
			hold->next = scout->next;
			scout->next = hold;
		}
		else if (!cmp(hold->data, scout->data))
		{
			trail->next = hold->next;
			hold->next = scout->next;
			scout->next = hold;
			scout = *lst;
		}
		else
			trail = hold;
	}
}
