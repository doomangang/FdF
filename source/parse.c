/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:34:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/11 15:56:03 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	get_map(int fd, t_mapinfo *map)
{
	char	*map_arr;
	char	**tmp;
	int		row;

	map_arr = read_map(fd, map);
	if (!map_arr)
	{
		free(map);
		handle_empty();
	}
	tmp = ft_split(map_arr, '\n');
	free(map_arr);
	map->height = count_height(tmp);
	map->width = (int)s_cnt(tmp[0], ' ');
	map->map = (t_coord **)malloc(sizeof(t_coord *) * map->width);
	if (!map->map)
		free_map(map, "malloc failed");
	row = -1;
	while (++row != map->width)
	{
		map->map[row] = (t_coord *)malloc(sizeof(t_coord) * map->height);
		if (!map->map[row])
			free_map(map, "malloc failed");
	}
	fill_map(tmp, map);
}

char	*read_map(int fd, t_mapinfo *map)
{
	int		status;
	char	buf[BUF_SIZE];
	char	*num_arr;
	char	*tmp;

	status = 1;
	status = read(fd, buf, BUF_SIZE - 1);
	if (status == -1)
		free_map(map, "read error");
	if (status >= BUF_SIZE - 1)
	{
		tmp = read_map(fd, map);
		num_arr = ft_strjoin(buf, tmp);
		free(tmp);
	}
	else if (!status)
		return (0);
	else
	{
		buf[status] = 0;
		num_arr = ft_strdup(buf);
	}
	return (num_arr);
}

void	fill_map(char **arr, t_mapinfo *map)
{
	char	**num_arr;
	int		row;
	int		col;
	int		t_row;

	init_map(map);
	row = 0;
	while (arr[row])
	{
		num_arr = ft_split(arr[row], ' ');
		if (count_height(num_arr) != map->width)
			free_map(map, "map error");
		t_row = map->height - 1 - row;
		col = 0;
		while (col != map->width)
		{
			map->map[col][t_row].z = ft_atoi(num_arr[col]);
			col++;
		}
		set_them_free(num_arr);
		row++;
	}
	set_them_free(arr);
	projection(map);
}

int	count_height(char **arr)
{
	int		idx;
	int		cnt;

	idx = 0;
	cnt = 0;
	while (arr[idx] != NULL)
	{
		idx++;
		cnt++;
	}
	return (cnt);
}

void	init_map(t_mapinfo *map)
{
	int	row;
	int	col;

	row = 0;
	while (row != map->width)
	{
		col = 0;
		while (col != map->height)
		{
			map->map[row][col].x = row;
			map->map[row][col].y = col;
			col++;
		}
		row++;
	}
}
