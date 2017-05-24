/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 18:13:43 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/30 18:14:25 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

char	*get_string(int size)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(size + 1);
	fseek(stdin, 0, SEEK_END);
	fgets(str, size + 1, stdin);
	while (str[i] && str[i] != '\n')
		++i;
	str[i] = '\0';
	return (str);
}
