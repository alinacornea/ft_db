/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 02:17:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/03 03:51:43 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static int	check_list(char *input, char *file)
{
	int		fd;
	char	*line;

	if (!input)
		return (0);
	fd = open(file, O_RDONLY);
	line = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		if (!ft_strcmp(ft_tolowerstr(input), "print"))
			printf("- %s\n", ft_capitalize_each(line));
		else if (!ft_strcmp(ft_tolowerstr(input), line))
		{
			return (1);
			free(line);
			close(fd);
		}
	}
	free(line);
	close(fd);
	return (0);
}

char		*validate_input(char *input, char *file, char *str, int size)
{
	if (input)
		free(input);
	printf("Enter a valid %s or type \"print\" for a list: ", str);
	input = get_string(size);
	while (!check_list(input, file))
	{
		free(input);
		printf("Enter a valid %s or type \"print\" for a list: ", str);
		input = get_string(size);
	}
	return (input);
}
