/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:31:59 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 18:14:37 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calc_depth(t_mlx *data, int fractol_type, double z_re, double z_im)
{
	int	depth;

	depth = 0;
	if (fractol_type == MANDELBROT)
		depth = calc_mandelbrot(data, z_re, z_im);
	else if (fractol_type == JULIA)
		depth = calc_julia(data, z_re, z_im);
	else if (fractol_type == ORIGINAL)
		depth = calc_original(data, z_re, z_im);
	return (depth);
}

void	render_fractol(t_mlx *data, int fractol_type)
{
	int		x;
	int		y;
	double	z_re;
	double	z_im;
	int		depth;

	mlx_clear_window(data->mlx, data->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z_re = data->min_re + (double) x * (data->max_re - data->min_re) / WIDTH;
			z_im = data->max_im + (double) y * (data->min_im - data->max_im) / HEIGHT;
			depth = calc_depth(data, fractol_type, z_re, z_im);
			paint_plot(data, x, y, convert_depth_to_color(depth, data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}