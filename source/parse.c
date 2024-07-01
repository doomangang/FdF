/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:34:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/02 00:09:19 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

char	*get_next_line(int fd);

int	**init_map(char *file)
{
	int			fd;
	t_mapinfo	*map_info;
	int w;
	int h;

	fd = open(file, O_RDONLY);
	map_info->width = ft_strlen(get_next_line(fd));
	close(fd);
	map_info->height = count_line(file);
	map_info->map = create_map(map_info->width, map_info->height);
	w = 0;
	h = 0;
	while(h != map_info->height)
	{
		while(w != map_info->width)
		{
			map_info->map[h][w] = 0;
		}
	}
}

int	get_map(char *file, t_mapinfo *map)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_atoi(ft_split(line, ' '));
		line = get_next_line(fd);
	}
}

int	count_line(char *file)
{

}