/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:42:36 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/07 22:15:22 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/fdf.h"

void put_pixel(t_imagemeta *img, int x, int y, int heightor) {
    char *dst;

    if (x >= 0 && x < 1920 && y >= 0 && y < 1024) {
        dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
        *(unsigned int*)dst = heightor;
    }
}

void draw_line(t_imagemeta *img, int x0, int y0, int x1, int y1, int color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1) {
        put_pixel(img, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void calculate_scale_and_offset(t_mapinfo *map, double *scale, double *offset_x, double *offset_y) {
    double max_x = 0.0;
    double max_y = 0.0;

    // Find the maximum x and y coordinates
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            if (map->map[i][j].x > max_x) {
                max_x = map->map[i][j].x;
            }
            if (map->map[i][j].y > max_y) {
                max_y = map->map[i][j].y;
            }
        }
    }

    // Calculate scale based on the window size and map size
    double scale_x = (1920 - 100) / (max_x * 3 + 1);  // 100 pixels padding
    double scale_y = (1024 - 100) / (max_y * 3 + 1); // 100 pixels padding

    *scale = fmin(scale_x, scale_y);

    // Calculate offset to center the map in the window
    *offset_x = (1920 - max_x * (*scale)) / 2;
    *offset_y = (1024 - max_y * (*scale));
}

void    draw(t_imagemeta *img, t_mapinfo *map)
{
	double scale; // 적절한 크기로 조정
    double offset_x; // 화면 중앙에 배치
    double offset_y;

	calculate_scale_and_offset(map, &scale, &offset_x, &offset_y);
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            double x1 = map->map[i][j].x * scale + offset_x;
            double y1 = map->map[i][j].y * scale + offset_y;
            if (j < map->height - 1) {
                double x2 = map->map[i][j + 1].x * scale + offset_x;
                double y2 = map->map[i][j + 1].y * scale + offset_y;
                draw_line(img, round(x1), round(y1), round(x2), round(y2), 0x00FFFFFF);
            }
            if (i < map->width - 1) {
                double x2 = map->map[i + 1][j].x * scale + offset_x;
                double y2 = map->map[i + 1][j].y * scale + offset_y;
                draw_line(img, round(x1), round(y1), round(x2), round(y2), 0x00FFFFFF);
            }
        }
    }

}
