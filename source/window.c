/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:20:58 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/07 21:26:59 by jihyjeon         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_imagemeta *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	window(t_mapinfo *map)
{
	t_windata	w_data;
	t_imagemeta	img;

	w_data.mlx = mlx_init();
	w_data.win = mlx_new_window(w_data.mlx, 1920, 1024, "test");
	img.img = mlx_new_image(w_data.mlx, 1920, 1024);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	draw(&img, map);
	mlx_put_image_to_window(w_data.mlx, w_data.win, img.img, 0, 0);
	mlx_key_hook(w_data.win, key_hook, &w_data);
	mlx_hook(w_data.win, 17, 0, exit_hook, 0);
	mlx_loop(w_data.mlx);
	return (0);
}
