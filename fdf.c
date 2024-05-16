/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/05/11 19:37:31 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char		*file;
	t_mapinfo	*map;
	int			fd;
	int			status;

	if (argc == 2)
	{
		file = argv[2];
		fd = open(file, O_RDONLY);
		get_map(fd, map);
	}
	else
		perror("Input Error");
	return (0);
}
