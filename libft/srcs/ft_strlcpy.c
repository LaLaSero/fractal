/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:26:34 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/02 13:14:15 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t dst_size)
{
	size_t	i;

	if (dest == NULL && dst_size == 0)
		return (0);
	i = 0;
	while (dst_size != 0 && src[i] && i < dst_size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (dst_size != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
