/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:20:58 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/09 16:38:37 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	exit_hook(void)
{
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_windata *win)
{
	if (keycode == 53)
	{
		mlx_destroy_image(win->mlx, win->win);
		mlx_destroy_window(win->mlx, win->win);
		exit(0);
	}
	return (0);
}

int	window(t_mapinfo *map)
{
	t_windata	w_data;
	t_imagemeta	img;
	t_winfit	f;

	w_data.mlx = mlx_init();
	scale_offset(map, &f);
	w_data.w = 1920;
	w_data.h = 1024;
	w_data.win = mlx_new_window(w_data.mlx, w_data.w, w_data.h, "fdf");
	img.img = mlx_new_image(w_data.mlx, w_data.w, w_data.h);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lgth, &img.edn);
	scale_offset(map, &f);
	draw(&img, map, &f);
	mlx_put_image_to_window(w_data.mlx, w_data.win, img.img, 0, 0);
	mlx_key_hook(w_data.win, key_hook, &w_data);
	mlx_hook(w_data.win, 17, 0, exit_hook, 0);
	mlx_loop(w_data.mlx);
	return (0);
}

void	scale_offset(t_mapinfo *map, t_winfit *fit)
{
	int	i;
	int	j;

	i = 0;
	fit->max_x = map->map[0][0].x;
	fit->max_y = map->map[0][0].y;
	while (i != map->width)
	{
		j = 0;
		while (j != map->height)
		{
			if (map->map[i][j].x > fit->max_x)
				fit->max_x = map->map[i][j].x;
			if (map->map[i][j].y > fit->max_y)
				fit->max_y = map->map[i][j].y;
			j++;
		}
		i++;
	}
	fit->scale_x = (1920 - 100) / (fit->max_x * 2 + 1);
	fit->scale_y = (1024 - 100) / (fit->max_y * 2 + 1);
	fit->scale = fmin(fit->scale_y, fit->scale_x);
	fit->off_x = (1920 - fit->max_x * fit->scale_x) / 2;
	fit->off_y = (1024 - fit->max_y * fit->scale_y);
}
