/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:06:08 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/04 02:20:11 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static void	insert_type(t_wine *wine, t_wine *new, t_wine *type)
{
	int value;

	value = 0;
	if (type->sort_vin)
		value = ft_strcmp(ft_itoa(new->vintage), ft_itoa(wine->vintage));
	else if (type->sort_reg)
		value = ft_strcmp(new->region, wine->region);
	else if (type->sort_name)
		value = ft_strcmp(new->name, wine->name);
	else
		value = ft_strcmp(new->varietal, wine->varietal);
	if (value < 0)
	{
		if (wine->left != NULL)
			insert_type(wine->left, new, type);
		else
			wine->left = new;
	}
	else
	{
		if (wine->right != NULL)
			insert_type(wine->right, new, type);
		else
			wine->right = new;
	}
}

static void	get_tree_sort(t_wine **wine, char *filename, t_wine type)
{
	int		fd;
	char	*line;
	char	**split;
	t_wine	*new_node;

	fd = open(filename, O_RDONLY);
	line = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ',');
		if (!validate_db(split, *wine))
		{
			printf("Ignoring corrupt database line: %s\n", line);
			continue ;
		}
		new_node = init_node(split);
		if (*wine == NULL)
			*wine = new_node;
		else
			insert_type(*wine, new_node, &type);
		free(split);
	}
	free(line);
	close(fd);
}

static int	choose_sort_type(int choice, t_wine *type)
{
	ft_bzero(type, sizeof(t_wine));
	if (choice == 1)
	{
		printf("\x1b[34mSorting by vintage..displaying..\x1b[0m\n");
		type->sort_vin = 1;
	}
	else if (choice == 2)
	{
		printf("\x1b[34mSorting by label..displaying..\x1b[0m\n");
		type->sort_name = 1;
	}
	else if (choice == 3)
		printf("\x1b[34mSorting by varietal..displaying..\x1b[0m\n");
	else if (choice == 4)
	{
		printf("\x1b[34mSorting by region..displaying..\x1b[0m\n");
		type->sort_reg = 1;
	}
	else if (choice == 5)
		return (1);
	return (0);
}

void		sort_display(char *filename)
{
	int		done;
	int		choice;
	t_wine	type;
	t_wine	*wine;

	done = 0;
	while (!done)
	{
		wine = NULL;
		printf("\n\x1b[1mUpdate sort menu: \n1. Sort by vintage\n2. Sort by "
				"label\n3. Sort by varietal\n4. Sort by region\n5. Exit\n");
		printf("Enter sort choice: \x1b[1m\n");
		if (!scanf("%d", &choice) || 1 > choice || choice > 5)
		{
			printf("Key entered is not valid!\n");
			fseek(stdin, 0, SEEK_END);
		}
		else
		{
			done = choose_sort_type(choice, &type);
			get_tree_sort(&wine, filename, type);
			print_bntree(wine);
			reset_file(filename, wine);
		}
	}
}
