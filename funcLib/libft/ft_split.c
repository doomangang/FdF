/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:43:18 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/04 21:42:50 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	print_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

size_t	s_cnt(const char *str, char chr)
{
	size_t	num;

	num = 0;
	while (*str)
	{
		while (*str && (*str == chr))
			str++;
		if (*str)
			num++;
		while (*str && *str != chr)
			str++;
	}
	return (num);
}

size_t	s_len(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*c_arr(const char *str, char c)
{
	size_t	i;
	size_t	len;
	char	*new;

	len = s_len(str, c);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		print_error("malloc error");
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	nos;

	nos = s_cnt(s, c);
	arr = (char **)malloc(sizeof(char *) * (nos + 1));
	if (!(arr))
		print_error("malloc error");
	i = 0;
	while (*s != 0)
	{
		while (*s != 0 && (*s == c))
			s++;
		if (*s != 0)
		{
			arr[i] = c_arr(s, c);
			i++;
		}
		while (*s != 0 && !(*s == c))
			s++;
	}
	arr[i] = 0;
	return (arr);
}
