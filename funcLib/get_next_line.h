/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:42 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/01/30 22:56:16 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_a_line(int fd, char **line, char **rmd);
char	*join_the_buf(int fd, char *line, ssize_t *b_len);
ssize_t	newline_seeker(char *s);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, ssize_t blen);
void	*ft_memcpy(void *dst, void *src, size_t n);

#endif