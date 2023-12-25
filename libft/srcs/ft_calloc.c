/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:08:46 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/02 13:08:53 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*str;

	str = (void *) malloc(number * size);
	if (str == NULL)
		return (NULL);
	str = ft_memset(str, 0, number * size);
	return (str);
}