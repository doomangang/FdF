/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:43:11 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/04 21:40:36 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*tmp;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(new))
		print_error("malloc error");
	tmp = new;
	while (*s1)
	{
		*tmp = *s1;
		s1++;
		tmp++;
	}
	while (*s2)
	{
		*tmp = *s2;
		s2++;
		tmp++;
	}
	*tmp = '\0';
	return (new);
}
