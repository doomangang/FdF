/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:43:24 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/02 16:46:21 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	idx;
	char	*f_str;

	if (!f)
		return (0);
	s_len = ft_strlen(s);
	f_str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!(f_str))
		return (0);
	idx = -1;
	while (++idx != s_len)
		f_str[idx] = (*f)(idx, s[idx]);
	f_str[idx] = 0;
	return (f_str);
}
