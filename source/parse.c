/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:34:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/02 16:51:59 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

char	*read_map(int fd);

char	*get_map(int fd, t_mapinfo *map)
{
	char	*map_arr;

	map_arr = read_map(fd);
	// map->map = ft_split(map_arr, '\n');
	return (map_arr);
}

char	*read_map(int fd)
{
	int		idx;
	int		status;
	char	buf[BUF_SIZE];
	char	*num_arr;

	status = 1;
	idx = 0;
	status = read(fd, buf, BUF_SIZE);
	idx += status;
	if (status >= BUF_SIZE)
		num_arr = ft_strjoin(&buf, read_map(fd));
	else
		num_arr = ft_strdup(&buf);
	return (num_arr);
}
