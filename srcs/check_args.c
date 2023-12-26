/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:57:59 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 17:14:27 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		return (INVALID);
	str = argv[1];
	if (*str == '\0')
		return (INVALID);
	if (ft_strncmp(str, "mandelbrot", 11) == 0)
		return (MANDELBROT);
	else if (ft_strncmp(str, "julia", 6) == 0)
		return (JULIA);
	else if (ft_strncmp(str, "original", 9) == 0)
		return (ORIGINAL);
	else
		return (INVALID);
}

int	show_usage(void)
{
	ft_putstr_fd("Usage: ./fractol [mandelbrot | julia]\n", 1);
	return (0);
}