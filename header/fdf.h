/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/05 17:02:33 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx_mms_20191025_beta/mlx.h"
# include "../funcLib/libft/libft.h"

# define BUF_SIZE 10000

typedef struct s_mapinfo
{
	int		width;
	int		height;
	int		**map;
}			t_mapinfo;

typedef struct s_windata
{
	void	*mlx;
	void	*win;
}			t_windata;

typedef struct s_imagemeta
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_imagemeta;

int		check_file(char *file);
void	get_map(int fd, t_mapinfo *map);
char	*read_map(int fd, t_mapinfo *map);
void	fill_map(char **arr, t_mapinfo *map);
int		count_height(char **arr);
void	free_map(t_mapinfo *map, char *str);
int		window(void);

#endif
