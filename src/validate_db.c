/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_db.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 02:17:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/04 02:09:28 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static int	check_line(char *input, char *file)
{
	int		fd;
	char	*line;

	if (!input)
		return (0);
	fd = open(file, O_RDONLY);
	line = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		if (!ft_strcmp(ft_tolowerstr(input), line))
		{
			input = ft_capitalize_each(input);
			free(line);
			close(fd);
			return (1);
		}
	}
	free(line);
	close(fd);
	printf("Bad input: %s.\n", input);
	return (0);
}

int			validate_db(char **split, t_wine *wine)
{
	if (!split[0] || !split[1] || !split[2] || !split[3] || !split[4] ||
		!split[5] || split[6] || ft_atoi(split[0]) <= 0)
		return (0);
	else if (search_key(wine, ft_atoi(split[0])))
	{
		printf("Duplicate key detected.\n");
		return (0);
	}
	else if (1970 > ft_atoi(split[1]) || ft_atoi(split[1]) > 2017)
	{
		printf("Detected vintage outside of range.\n");
		return (0);
	}
	else if (!check_line(split[3], "resources/varietals.key") ||
		!check_line(split[4], "resources/colors.key") ||
		!check_line(split[5], "resources/regions.key"))
		return (0);
	return (1);
}
