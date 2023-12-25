/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:57:59 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/25 13:32:55 by yutakagi         ###   ########.fr       */
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
	else
		return (INVALID);
}

int	show_usage(void)
{
	ft_putstr_fd("Usage: ./fractol [mandelbrot | julia]\n", 1);
	return (0);
}