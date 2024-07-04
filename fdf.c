/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/04 19:00:07 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/fdf.h"


int	main(int argc, char **argv)
{
	char		*file;	
	t_mapinfo	*map;
	int			flag;

	file = "../test_maps/42.fdf";
	map = (t_mapinfo *)malloc(sizeof(t_mapinfo));
	if (!map)
		free_map(map, "malloc failed");
	get_map(file, map);
}

void	free_map(t_mapinfo *map, char *str)
{
	if (map->map)
		free(map->map);
	if (map)
		free(map);
	perror(str);
	exit(EXIT_FAILURE);
}
