/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/02 16:54:02 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../funcLib/libft/libft.h"
#include "../funcLib/libft/ft_split.c"
#include "../funcLib/libft/ft_strjoin.c"
#include "../funcLib/libft/ft_strlen.c"
#include "../funcLib/libft/ft_strdup.c"
#include "../funcLib/libft/ft_strlcpy.c"
#include "../funcLib/libft/ft_memcpy.c"


# define BUF_SIZE 10000

typedef struct s_mapinfo
{
	long long	width;
	long long	height;
	char		**map;
}	t_mapinfo;


#endif
