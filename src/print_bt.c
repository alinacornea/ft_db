/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:13:05 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/03 22:19:50 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static void	print_tree(t_wine *wine)
{
	if (!wine)
		return ;
	if (wine->left)
		print_tree(wine->left);
	if (ft_strcmp(wine->color, "Red") == 0)
	{
		printf("\x1b[1m%-8d\x1b[33m%-10d\x1b[37m%-30s\x1b[3m\x1b[31m%-25s" \
		"\x1b[37m%-25s\x1b[0m\n", wine->key, wine->vintage, wine->name, \
		wine->varietal, wine->region);
	}
	if (ft_strcmp(wine->color, "White") == 0)
	{
		printf("\x1b[1m%-8d\x1b[33m%-10d\x1b[37m%-30s\x1b[3m\x1b[37m%-25s" \
		"\x1b[37m%-25s\x1b[0m\n", wine->key, wine->vintage, wine->name, \
		wine->varietal, wine->region);
	}
	if (ft_strcmp(wine->color, "Rose") == 0)
	{
		printf("\x1b[1m%-8d\x1b[33m%-10d\x1b[37m%-30s\x1b[3m\x1b[35m%-25s" \
		"\x1b[37m%-25s\x1b[0m\n", wine->key, wine->vintage, wine->name, \
		wine->varietal, wine->region);
	}
	if (wine->right)
		print_tree(wine->right);
}

void		print_bntree(t_wine *wine)
{
	if (!wine)
		return ;
	printf("\e[1;96m\e[34m%-8s%-10s%-30s%-25s%-25s\e[0m\n", "KEY",
		"VINTAGE", "LABEL", "VARIETAL", "REGION");
	print_tree(wine);
}
