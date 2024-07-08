/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/08 21:39:48 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_mms_20191025_beta/mlx.h"
# include "../funcLib/libft/libft.h"

# define BUF_SIZE 10000
# define WH 0x00FFFFFF

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}			t_coord;

typedef struct s_mapinfo
{
	int		width;
	int		height;
	t_coord	**map;
}			t_mapinfo;

typedef struct s_windata
{
	void	*mlx;
	void	*win;
}			t_windata;

typedef struct s_pixel
{
	int	x;
	int	y;
}		t_pixel;

typedef struct s_imagemeta
{
	void	*img;
	char	*addr;
	t_pixel	**p_map;
	int		bpp;
	int		line_lgth;
	int		edn;
}			t_imagemeta;

typedef struct s_winfit
{
	double	scale;
	double	off_x;
	double	off_y;
	double	max_x;
	double	max_y;
	double	scale_x;
	double	scale_y;
}			t_winfit;

typedef struct s_bpoint
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
}			t_bpoint;

int		check_file(char *file);
void	get_map(int fd, t_mapinfo *map);
char	*read_map(int fd, t_mapinfo *map);
void	fill_map(char **arr, t_mapinfo *map);
int		count_height(char **arr);
void	free_map(t_mapinfo *map, char *str);
int	window(t_mapinfo *map);
void	projection(t_mapinfo *map);
void    draw(t_imagemeta *img, t_mapinfo *map);

#endif
