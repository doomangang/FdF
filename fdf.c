/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/04 21:54:52 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/fdf.h"


int	main(int argc, char **argv)
{
	char		*file;	
	t_mapinfo	*map;
    int         row;
    int         col;

	if (argc == 2)
	{
		file = argv[1];
		if (!check_file(file))
			free_map(0, "file should be in ~.fdf format");
		map = (t_mapinfo *)malloc(sizeof(t_mapinfo));
		if (!map)
			free_map(map, "malloc failed");
		get_map(file, map);
        row = 0;
        while(row != map->height)
        {
            col = 0;
            while(col != map->width)
            {
                printf("%d\t",map->map[row][col]);
                col++;
            }
            printf("\n");
            row++;
        }
	}
	else
	{
		perror("no fdf file input");
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
	if (map)
	{
		free(map);
		if (map->map)
			free(map->map);
	}
	perror(str);
	exit(EXIT_FAILURE);
}
