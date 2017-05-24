/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_db.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:11:43 by alcornea          #+#    #+#             */
/*   Updated: 2017/05/04 01:47:53 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			populate_bnt(t_wine **wine, int fd, char *filename)
{
	t_wine	*new_node;
	char	**split;
	char	*line;

	line = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ',');
		if (!validate_db(split, *wine))
		{
			ft_printf("Ignoring corrupt database line: %s\n", line);
			continue ;
		}
		new_node = init_node(split);
		if (*wine == NULL)
			*wine = new_node;
		else
			insert(*wine, new_node);
		free(split);
	}
	reset_file(filename, *wine);
	free(line);
}
