/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:22:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/03 18:59:56 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static int	generate_key(t_wine *wine)
{
	int	i;

	i = 1;
	while (search_key(wine, i))
		++i;
	return (i);
}

static void	enter_value(t_wine *new, t_wine *wine)
{
	new->key = generate_key(wine);
	printf("Enter vintage:\n");
	while (!scanf("%d", &new->vintage) ||
		1970 > new->vintage || new->vintage > 2016)
	{
		ft_printf("Please enter a vintage between 1970 and 2016: ");
		fseek(stdin, 0, SEEK_END);
	}
	printf("Enter label: \n");
	new->name = ft_capitalize_each(get_string(MAX_LABEL));
	new->varietal = ft_capitalize_each(validate_input(new->varietal,
			"resources/varietals.key", "varietal", MAX_VARIETAL));
	new->region = ft_capitalize_each(validate_input(new->region,
			"resources/regions.key", "region", MAX_REGION));
	new->color = ft_capitalize_each(validate_input(new->color,
			"resources/colors.key", "color", MAX_COLOR));
}

void		add(char *file)
{
	int		fd;
	FILE	*fp;
	t_wine	*new;
	t_wine	*wine;

	wine = NULL;
	fd = open(file, O_RDONLY | O_CREAT, 0777);
	populate_bnt(&wine, fd, file);
	close(fd);
	new = ft_memalloc(sizeof(t_wine));
	ft_bzero(new, sizeof(t_wine));
	print_bntree(wine);
	enter_value(new, wine);
	printf("\e[1;96m\e[41m%-8d%-10d%-30s%-25s%-25s\e[0m\n", new->key,
		new->vintage, new->name, new->varietal, new->region);
	printf("Line added\n");
	fp = fopen(file, "a+");
	serialize(new, fp);
	fclose(fp);
	free(new->region);
	free(new->color);
	free(new->name);
	free(new->varietal);
	free(new);
}
