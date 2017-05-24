/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_bn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:11:53 by alcornea          #+#    #+#             */
/*   Updated: 2017/04/30 23:31:54 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void		insert(t_wine *wine, t_wine *new)
{
	if (new->key < wine->key)
	{
		if (wine->left != NULL)
			insert(wine->left, new);
		else
			wine->left = new;
	}
	else
	{
		if (wine->right != NULL)
			insert(wine->right, new);
		else
			wine->right = new;
	}
}
