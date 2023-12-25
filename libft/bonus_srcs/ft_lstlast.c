/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:23:42 by yutakagi          #+#    #+#             */
/*   Updated: 2023/09/29 15:23:42 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_p;

	if (lst == NULL)
		return (NULL);
	last_p = lst;
	while (last_p -> next != NULL)
		last_p = last_p -> next;
	return (last_p);
}
