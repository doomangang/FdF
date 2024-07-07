/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/07 20:16:16 by jihyjeon         ###   ########.fr       */
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
		if (!check_file(file) || fd < 0 || read(fd, NULL, 0) == -1)
			free_map(0, "file error");
		map = (t_mapinfo *)malloc(sizeof(t_mapinfo));
		if (!map)
			free_map(0, "malloc failed");
		get_map(fd, map);
		close(fd);
		window();
	}
	else
	{
		perror("no apt file input");
		exit(EXIT_FAILURE);
	}
}

int	check_file(char *file)
{
	char	**parsed;
	int		h;

	parsed = ft_split(file, '.');
	h = count_height(parsed);
	if ((!ft_strncmp(parsed[h - 1], "fdf", 3)) && ft_strlen(parsed[h - 1]) == 3)
		return (1);
	return (0);
}

void	free_map(t_mapinfo *map, char *str)
{
    int	row;

	row = 0;
	if (map)
	{
		if (map->map)
        {
            while (row != map->width)
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
	perror(str);
	exit(EXIT_FAILURE);
}
