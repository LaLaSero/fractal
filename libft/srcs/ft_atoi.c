/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:33:24 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/02 13:13:03 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *string)
{
	int	flag;
	int	result;

	while (*string == ' ' || *string == '\t' || *string == '\n'
		|| *string == '\v' || *string == '\f' || *string == '\r')
		string++;
	flag = 1;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			flag *= -1;
		string++;
	}
	result = 0;
	while (*string >= '0' && *string <= '9')
	{
		if (result * flag > INT_MAX / 10 
			|| (result * flag == INT_MAX / 10 && *string - '0' > 7))
			return ((int)LONG_MAX);
		if (result * flag < INT_MIN / 10
			|| (result * flag == INT_MIN / 10 && *string - '0' > 8))
			return ((int)LONG_MIN);
		result = result * 10 + (*string++ - '0');
	}
	return (result * flag);
}

// #include<stdio.h>
// int main()
// {
// 	char *str = "   9223372036854775807";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	return (0);
// }