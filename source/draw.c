/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:42:36 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/08 21:42:44 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	put_pixel(t_imagemeta *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1024)
	{
		dst = img->addr + (y * img->line_lgth + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

// void	draw_line(t_imagemeta *img, t_bpoint b)
// {
// 	int	x;
// 	int	y;
// 	int	w;
// 	int	h;
// 	int	f;
// 	int	df1;
// 	int	df2;
// 	int	i;

// 	x = (int)round(b.x1);
// 	y = round(b.y1);
// 	w = abs((int)round(b.x2) - x);
// 	h = abs((int)round(b.y2) - y);
// 	f = 2 * h - w;
// 	df1 = 2 * h;
// 	df2 = 2 * (h - w);
// 	i = x;
// 	while (i != x + w + 1)
// 	{
// 		put_pixel(img, x, y, WH);
// 		if (f < 0)
// 			f = df1;
// 		else
// 		{
// 			y++;
// 			f += df2;
// 		}
// 		i++;
// 	}
// }

void	draw_line(t_imagemeta *img, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		put_pixel(img, x0, y0, WH);
		if (x0 == x1 && y0 == y1) break;
		e2 = err;
		if (e2 > -dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void	calculate_scale_and_offset(t_mapinfo *map, t_winfit *fit)
{
	int	i;
	int	j;

	fit->max_x = map->map[0][0].x;
	fit->max_y = map->map[0][0].y;
	i = 0;
	while (i != map->width)
	{
		j = 0;
		while (j != map->height)
		{
			if (map->map[i][j].x > fit->max_x) {
				fit->max_x = map->map[i][j].x;
			}
			if (map->map[i][j].y > fit->max_y) {
				fit->max_y = map->map[i][j].y;
			}
			j++;
		}
		i++;
	}
	fit->scale_x = (1920 - 100) / (fit->max_x * 2 + 1);
	fit->scale_y = (1024 - 100) / (fit->max_y * 2 + 1);
	fit->scale = fmin(fit->scale_x, fit->scale_y);
	fit->off_x = (1920 - fit->max_x * fit->scale_x) / 2;
	fit->off_y = (1024 - fit->max_y * fit->scale_y);
}

void	set_point(t_coord **map, t_winfit f, t_imagemeta *img)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;

	
}

void    draw(t_imagemeta *img, t_mapinfo *map)
{
	int			i;
	int			j;
	t_winfit	f;

	calculate_scale_and_offset(map, &f);
	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			b.x1 = map->map[i][j].x * f.scale + f.off_x;
			b.y1 = map->map[i][j].y * f.scale + f.off_y;
			if (j < map->height - 1)
			{b.x2 = map->map[i][j + 1].x * f.scale + f.off_x;
			b.y2 = map->map[i][j + 1].y * f.scale + f.off_y;
			draw_line(img, round(b.x1), round(b.y1), round(b.x2), round(b.y2));}
			if (i < map->width - 1)
			{b.x2 = map->map[i + 1][j].x * f.scale + f.off_x;
			b.y2 = map->map[i + 1][j].y * f.scale + f.off_y;
			draw_line(img, round(b.x1), round(b.y1), round(b.x2), round(b.y2));}
			j++;
		}
		i++;
	}
}
