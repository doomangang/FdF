/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:07:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/09 20:32:54 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	draw(t_imagemeta *img, t_windata *win, t_mapinfo *map, t_winfit *f)
{
	int			i;
	int			j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			enlarge(&map->map[i][j], &f->p1, f);
			if (j < map->height - 1)
			{
				enlarge(&map->map[i][j + 1], &f->p2, f);
				draw_line(img, win, f->p1, f->p2);
			}
			if (i < map->width - 1)
			{
				enlarge(&map->map[i + 1][j], &f->p2, f);
				draw_line(img, win, f->p1, f->p2);
			}
			j++;
		}
		i++;
	}
}

void	enlarge(t_coord *src, t_coord *dst, t_winfit *f)
{
	dst->x = round(src->x * f->scale + f->off_x);
	dst->y = round((src->y + f->max_y) * f->scale + f->off_y);
}

void	draw_line(t_imagemeta *img, t_windata *win, t_coord p1, t_coord p2)
{
	t_lineinfo	l;

	l.dx = fabs(p2.x - p1.x);
	l.dy = fabs(p2.y - p1.y);
	l.sx = p1.x < p2.x ? 1 : -1;
	l.sy = p1.y < p2.y ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	while (1)
	{
		put_pixel(img, win, p1.x, p1.y);
		if (p1.x == p2.x && p1.y == p2.y) break;
		l.e2 = l.err;
		if (l.e2 > -l.dx) { l.err -= l.dy; p1.x += l.sx; }
		if (l.e2 < l.dy) { l.err += l.dx; p1.y += l.sy; }
	}
}

void	put_pixel(t_imagemeta *img, t_windata *win, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < win->w && y >= 0 && y < win->h)
	{
		dst = img->addr + (y * img->line_lgth + x * (img->bpp / 8));
		*(unsigned int *)dst = WH;
	}
}
