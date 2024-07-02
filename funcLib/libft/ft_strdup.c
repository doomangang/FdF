/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:53:07 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/02 16:46:21 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ptr))
		return (0);
	ft_strlcpy(ptr, src, len + 1);
	return (ptr);
}
