/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:27:19 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/03 17:57:45 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static t_wine		*min_val(t_wine *node)
{
	t_wine	*current;

	current = node;
	while (current->left != NULL)
		current = current->left;
	return (current);
}

t_wine				*check_nodes(t_wine *root, t_wine *temp)
{
	if (root->left == NULL)
	{
		temp = root;
		root = root->right;
		free(temp);
	}
	else if (root->right == NULL)
	{
		temp = root;
		root = root->left;
		free(temp);
	}
	return (root);
}

static t_wine		*delete_key(t_wine *root, t_wine *temp, int key)
{
	if (root == NULL)
		return (root);
	if (key < root->key)
		root->left = delete_key(root->left, NULL, key);
	else if (key > root->key)
		root->right = delete_key(root->right, NULL, key);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL || root->right == NULL)
			root = check_nodes(root, temp);
		else
		{
			temp = min_val(root->right);
			root->key = temp->key;
			root->right = delete_key(root->right, NULL, temp->key);
		}
	}
	return (root);
}

void				delete(char *filename)
{
	int		fd;
	int		key;
	t_wine	*wine;
	t_wine	*tmp;

	wine = NULL;
	fd = open(filename, O_RDONLY);
	populate_bnt(&wine, fd, filename);
	close(fd);
	print_bntree(wine);
	printf("Enter key to delete: ");
	while (!scanf("%d", &key) || !(tmp = search_key(wine, key)))
	{
		printf("Key entered is not valid\n"
			"Enter a key to delete: ");
		fseek(stdin, 0, SEEK_END);
	}
	printf("\e[1;96m\e[41m%-8d%-10d%-30s%-25s%-25s\e[0m\n", tmp->key,
		tmp->vintage, tmp->name, tmp->varietal, tmp->region);
	wine = delete_key(wine, NULL, key);
	printf("Line deleted\n");
	reset_file(filename, wine);
}
