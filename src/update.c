/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:23:49 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/03 22:45:48 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static void	update_menu_step(t_wine *tmp, int key)
{
	if (key == 3)
	{
		ft_printf("New label: ");
		tmp->name = get_string(MAX_LABEL);
	}
	else if (key == 4)
		tmp->varietal = validate_input(tmp->varietal,
				"resources/varietals.key", "new varietal", MAX_VARIETAL);
	else if (key == 5)
		tmp->region = validate_input(tmp->region,
				"resources/regions.key", "new region", MAX_REGION);
	else if (key == 6)
		tmp->color = validate_input(tmp->color,
				"resources/colors.key", "new color", MAX_COLOR);
	else if (key == 7)
		;
	else
		ft_printf("Invalid key!\n");
}

static void	update_menu(t_wine *wine, t_wine *tmp, int key)
{
	if (key == 1)
	{
		ft_printf("New key: ");
		while (!scanf("%d", &key) || key <= 0 ||
			search_key(wine, key))
		{
			ft_printf("Please enter a valid, unique key: ");
			fseek(stdin, 0, SEEK_END);
		}
		tmp->key = key;
	}
	else if (key == 2)
	{
		ft_printf("New vintage: ");
		while (!scanf("%d", &tmp->vintage) ||
			1970 > tmp->vintage || tmp->vintage > 2016)
		{
			ft_printf("Please enter a vintage between 1970 and 2016: ");
			fseek(stdin, 0, SEEK_END);
		}
	}
	else
		update_menu_step(tmp, key);
}

static void	change_loop(t_wine *wine, t_wine *tmp, int key)
{
	printf("\e[1;96m\e[41m%-8d%-10d%-15s%-15s%-15s%-15s\e[0m\n", tmp->key,
			tmp->vintage, tmp->name, tmp->varietal, tmp->color, tmp->region);
	ft_printf("\x1b[1mUpdate menu: \n1. Change key\n2. Change vintage\n" \
			"3. Change label\n4. Change varietal\n5. Change region\n" \
			"6. Change color\n7. Exit\nYour selection: \x1b[0m");
	while (!scanf("%d", &key) || 1 > key || key > 7)
	{
		ft_printf("Please enter a choice 1 - 7\n");
		fseek(stdin, 0, SEEK_END);
	}
	update_menu(wine, tmp, key);
	printf("\e[1;96m\e[41m%-8d%-10d%-15s%-15s%-15s%-15s\e[0m\n", tmp->key,
			tmp->vintage, tmp->name, tmp->varietal, tmp->color, tmp->region);
}

static void	update_loop(char *filename, t_wine *wine, int key)
{
	t_wine	*tmp;

	while (key)
	{
		ft_printf("Enter the wine key you wish to update "
				"or type \"0\" to save and exit: ");
		while (!scanf("%d", &key) || key < 0)
		{
			ft_printf("Please enter a valid key: ");
			fseek(stdin, 0, SEEK_END);
		}
		if ((tmp = search_key(wine, key)))
			change_loop(wine, tmp, key);
		else if (key > 0)
			ft_printf("Key not found.\n");
	}
	reset_file(filename, wine);
}

void		update(char *filename)
{
	int		fd;
	t_wine	*wine;

	wine = NULL;
	fd = open(filename, O_RDONLY | O_CREAT, 0777);
	populate_bnt(&wine, fd, filename);
	close(fd);
	print_bntree(wine);
	update_loop(filename, wine, 1);
}
