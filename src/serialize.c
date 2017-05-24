/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:50:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/01 00:29:26 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void	serialize(t_wine *wine, FILE *fp)
{
	if (!wine)
		return ;
	if (wine->left)
		serialize(wine->left, fp);
	fprintf(fp, "%d,%d,%s,%s,%s,%s\n", wine->key, wine->vintage,
		ft_capitalize_each(wine->name),
		ft_capitalize_each(wine->varietal),
		ft_capitalize_each(wine->color),
		ft_capitalize_each(wine->region));
	if (wine->right)
		serialize(wine->right, fp);
}
