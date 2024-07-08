/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:55:40 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/08 13:36:04 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	calculate(t_coord *point)
{
	double	x;
	double	y;
	double	z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x = (x + y) / sqrt(2);
	point->y = (x - 2 * z - y) / sqrt(6);
	point->z = 0;
}

void	projection(t_mapinfo *map)
{
	int	row;
	int	col;

	row = 0;
	while (row != map->width)
	{
		col = 0;
		while (col != map->height)
		{
			calculate(&map->map[row][col]);
			col++;
		}
		row++;
	}
}
