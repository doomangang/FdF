/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/13 21:01:54 by jihyjeon         ###   ########.fr       */
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
	int		w;
	int		h;
}			t_windata;

typedef struct s_imagemeta
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lgth;
	int		edn;
}			t_imagemeta;

typedef struct s_winfit
{
	int		scale;
	int		off_x;
	int		off_y;
	double	max_x;
	double	max_y;
	double	min_x;
	double	min_y;
	int		scale_x;
	int		scale_y;
	int		pad;
	t_coord	p1;
	t_coord	p2;
}			t_winfit;

typedef struct s_lineinfo
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}		t_lineinfo;

int		check_file(char *file);
void	handle_error(char *str);
void	get_map(int fd, t_mapinfo *map);
char	*read_map(int fd, t_mapinfo *map);
void	fill_map(char **arr, t_mapinfo *map);
int		count_height(char **arr);
void	init_map(t_mapinfo *map);
void	free_map(t_mapinfo *map, int i, char *str);
void	free_arr(char **map);
void	window(t_mapinfo *map);
void	projection(t_mapinfo *map);
void	scale_offset(t_winfit *fit, t_windata *win);
void	max_point(t_winfit *fit, t_mapinfo *map);
void	draw(t_imagemeta *img, t_windata *win, t_mapinfo *map, t_winfit *f);
void	enlarge(t_coord *src, t_coord *dst, t_winfit *f);
void	draw_line(t_imagemeta *img, t_windata *win, t_coord p1, t_coord p2);
void	init_lineinfo(t_lineinfo *l, t_coord p1, t_coord p2);
void	put_pixel(t_imagemeta *img, t_windata *win, int x, int y);

#endif
