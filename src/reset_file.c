/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 04:49:26 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/01 04:50:00 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void	reset_file(char *filename, t_wine *wine)
{
	FILE	*fp;

	fp = fopen(filename, "w");
	serialize(wine, fp);
	fclose(fp);
}
