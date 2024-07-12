/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/12 14:31:50 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/fdf.h"

int	main(int argc, char **argv)
{
	char		*file;	
	t_mapinfo	*map;
	int			fd;

	if (argc == 2)
	{
		file = argv[1];
		fd = open(file, O_RDONLY);
		if (!check_file(file))
			handle_error("Error : wrong file format\n");
		if (fd < 0)
			handle_error("Error : file doesn't exist or unable to open\n");
		if (read(fd, NULL, 0) == -1)
			handle_error("Error : file cannot be read");
		map = (t_mapinfo *)malloc(sizeof(t_mapinfo));
		if (!map)
			handle_error("Error : malloc failed\n");
		get_map(fd, map);
		close(fd);
		window(map);
	}
	else
		handle_error("Error : wrong file input\n");
}

int	check_file(char *file)
{
	char	**parsed;
	int		h;
	int		len;
	int		flag;

	flag = 0;
	parsed = ft_split(file, '.');
	h = count_height(parsed);
	len = ft_strlen(parsed[h - 1]);
	if (h == 2 && (!ft_strncmp(parsed[h - 1], "fdf", 3)) && len == 3)
		flag = 1;
	set_them_free(parsed);
	return (flag);
}

void	free_map(t_mapinfo *map, int i, char *str)
{
	int	row;

	row = 0;
	if (map)
	{
		if (map->map && *map->map)
		{
			while (row != i)
			{
				free(map->map[row]);
				map->map[row] = 0;
				row++;
			}
			free(map->map);
			map->map = 0;
		}
		free(map);
		map = 0;
	}
	if (str)
	{
		handle_error(str);
		exit(EXIT_FAILURE);
	}
}

void	set_them_free(char **arr)
{
	int	row;
	int	col;

	row = 0;
	while (arr[row])
	{
		col = 0;
		free(arr[row]);
		arr[row] = 0;
		row++;
	}
	free(arr);
	arr = 0;
}

void	handle_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
