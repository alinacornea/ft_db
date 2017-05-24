/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 03:55:52 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/01 03:56:58 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

t_wine	*init_node(char **split)
{
	t_wine	*new_node;

	new_node = ft_memalloc(sizeof(t_wine));
	new_node->key = ft_atoi(split[0]);
	new_node->vintage = ft_atoi(split[1]);
	new_node->name = split[2];
	new_node->varietal = split[3];
	new_node->color = split[4];
	new_node->region = split[5];
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
