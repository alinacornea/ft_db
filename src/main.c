/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:53:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/03 03:52:21 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static void	choose_menu(char *filename, int choice)
{
	if (choice == 1)
		add(filename);
	else if (choice == 2)
		delete(filename);
	else if (choice == 3)
		search_display(filename);
	else if (choice == 4)
		sort_display(filename);
	else if (choice == 5)
		update(filename);
	else if (choice == 6)
		exit(0);
	else
		ft_printf("Please use keys 1 - 6 to make your choice.\n");
}

int			main(int ac, char **av)
{
	int	choice;

	if (ac == 2)
	{
		while (1)
		{
			printf("\x1b[1mMenu: \n1. Add a record\n2. Delete a record\n"
					"3. Search and display a record\n4. "
					"Sort and display all records\n5. Update a record\n"
					"6. Exit\nEnter your choice: \x1b[0m ");
			if (!scanf("%d", &choice))
			{
				ft_printf("Please use keys 1 - 6 to make your choice.\n");
				fseek(stdin, 0, SEEK_END);
				continue ;
			}
			else
				choose_menu(av[1], choice);
		}
	}
	else
		ft_printf("USAGE: ./wine_db [wine database name]\n");
	return (0);
}
