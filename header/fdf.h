/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/04 21:33:44 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../funcLib/libft/libft.h"

# define BUF_SIZE 10000

typedef struct s_mapinfo
{
	int		width;
	int		height;
	int		**map;
}	t_mapinfo;

int		check_file(char *file);
void	get_map(char *file, t_mapinfo *map);
char	*read_map(int fd, t_mapinfo *map);
void	fill_map(char **arr, t_mapinfo *map);
int		count_height(char **arr);
void	free_map(t_mapinfo *map, char *str);

#endif
