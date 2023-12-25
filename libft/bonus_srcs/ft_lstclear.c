/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:08:10 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/02 12:08:10 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst == NULL || del == NULL || *lst == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		tmp = *lst;
		del ((*lst) -> content);
		*lst = (*lst) -> next;
		free(tmp);
	}
	*lst = NULL;
}
