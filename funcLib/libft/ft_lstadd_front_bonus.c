/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:51:32 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/02 16:46:21 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(lst) || !(new))
		return ;
	new->next = (*lst);
	(*lst) = new;
}
