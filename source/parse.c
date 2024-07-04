/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:34:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/04 20:06:44 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

char	*get_map(char *file, t_mapinfo *map)
{
	char	*map_arr;
	char	**tmp;
	char	*num;
	int		idx;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		free_map(map, "file error");
	map_arr = read_map(fd, map);
	tmp = ft_split(map_arr, '\n');
	free(map_arr);
	map->height = count_height(tmp);
	map->width = (int)s_cnt(tmp[0], ' ');
	map->map = (int **)malloc(sizeof(int *) * map->height);
	if (!map->map)
		free_map(map, "malloc failed");
	fill_map(tmp, map);
	free(tmp);
	close(fd);
	return (map_arr);
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
		num_arr = ft_strjoin(&buf, tmp);
		free(tmp);
	}
	else
		num_arr = ft_strdup(&buf);
	return (num_arr);
}

char	**fill_map(char **arr, t_mapinfo *map)
{
	char	**num_arr;
	int		row;
	int		col;

	row = 0;
	while (arr[row])
	{
		map->map[row] = (int *)malloc(sizeof(int) * map->width);
		if (!map->map[row])
			free_map(map, "malloc failed");
		num_arr = ft_split(arr[row], ' ');
		if (count_height(num_arr) != map->width)
			free_map(map, "map error");
		col = 0;
		while (col != map->width)
		{
			map->map[row][col] = ft_atoi(num_arr[col]);
			col++;
		}
		row++;
	}
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
