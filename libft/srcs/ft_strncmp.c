/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:40:38 by marvin            #+#    #+#             */
/*   Updated: 2023/09/28 10:40:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *) s1;
	q = (unsigned char *) s2;
	i = 0;
	while (i < n && p[i] == q[i] && p[i] != '\0' && q[i] != '\0')
		i++;
	if (i == n || p[i] == q[i])
		return (0);
	if (p[i] > q[i])
		return (1);
	return (-1);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	const char s1[] = "ABCD";
// 	const char s2[] = "ABC";
// 	size_t i = 0;
// 	printf("%d\n",ft_strncmp(s1,s2,i));
// 	printf("%d\n",strncmp(s1,s2,i));
// }