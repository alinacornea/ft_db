/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:03:22 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/03 23:39:32 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static int	search_loop(int key, t_wine *wine)
{
	printf("Enter search key or type \"0\" to exit: ");
	if (!scanf("%d", &key))
	{
		printf("Enter a valid key number, not a character!\n");
		fseek(stdin, 0, SEEK_END);
	}
	else if (key > 0 && (wine = search_key(wine, key)))
	{
		printf("\e[1;96m\e[41m%-8d%-10d%-30s%-25s%-25s\e[0m\n",
				wine->key, wine->vintage, wine->name,
				wine->varietal, wine->region);
	}
	else if (!key)
		;
	else
		printf("Key entered not found\n");
	return (key);
}

void		search_display(char *filename)
{
	int		fd;
	int		key;
	t_wine	*tmp;
	t_wine	*wine;

	wine = NULL;
	fd = open(filename, O_RDONLY | O_CREAT);
	populate_bnt(&wine, fd, filename);
	close(fd);
	print_bntree(wine);
	tmp = wine;
	key = 1;
	while (key)
	{
		wine = tmp;
		key = search_loop(key, wine);
	}
}
