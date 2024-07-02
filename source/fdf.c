/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/02 16:54:37 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
#include "../source/parse.c"


char	*get_map(int fd, t_mapinfo *map);

int	main(int argc, char **argv)
{
	char		*file;
	t_mapinfo	*map;
	int			fd;
	int			i;

	// if (argc == 2)
	// {
		file = "../test_maps/42.fdf";
		fd = open(file, O_RDONLY);
		close(fd);
		printf("print:\n%s",get_map(fd, map));
	// }
	// else
	// 	perror("Input Error");
	// return (0);
}
