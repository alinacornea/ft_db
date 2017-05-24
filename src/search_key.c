/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:03:22 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/01 04:06:31 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

t_wine	*search_key(t_wine *ptr, int key)
{
	t_wine	*current;

	if (!ptr)
		return (ptr);
	if (ptr->key == key)
		return (ptr);
	else
	{
		current = NULL;
		if (ptr->left != NULL)
			current = search_key(ptr->left, key);
		if (current == NULL)
		{
			if (ptr->right != NULL)
				current = search_key(ptr->right, key);
		}
		return (current);
	}
}
