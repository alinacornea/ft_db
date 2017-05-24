/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 00:30:12 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/04 01:11:17 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_H
# define DB_H

# include "libft.h"
# include <stdio.h>
# include <math.h>

# define MAX_REGION 20
# define MAX_COLOR	10
# define MAX_LABEL 	25
# define MAX_VARIETAL 20
# define MIN(X,Y) (X) < (Y) ? -1 : 1

typedef struct		s_wine
{
	int				key;
	int				vintage;
	char			*name;
	char			*region;
	char			*varietal;
	char			*color;

	int				sort_vin;
	int				sort_reg;
	int				sort_name;
	struct s_wine	*left;
	struct s_wine	*right;

}					t_wine;

char				*validate_input(char *input, char *file,
						char *str, int size);
void				add(char *file);
void				delete(char *file);
void				update(char *file);
void				search_display(char *file);
void				sort_display(char *file);
char				*get_string(int size);
void				insert(t_wine *wine, t_wine *new);
void				serialize(t_wine *wine, FILE *fp);
void				populate_bnt(t_wine **wine, int fd, char *filename);
void				print_bntree(t_wine *wine);
void				reset_file(char *filename, t_wine *wine);
t_wine				*search_key(t_wine *ptr, int key);
t_wine				*init_node(char **split);
int					validate_db(char **split, t_wine *wine);

#endif
