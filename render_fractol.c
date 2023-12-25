/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:31:59 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 02:24:59 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	paint_plot(t_mlx *data, int x, int y, int color)
{
	int	pixel;

	pixel = (y * data->line_bytes) + (x * 4);
	if (data->endian == 1)
	{
		data->buffer[pixel + 0] = (color >> 24);
		data->buffer[pixel + 1] = (color >> 16) & 0xFF;
		data->buffer[pixel + 2] = (color >> 8) & 0xFF;
		data->buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (data->endian == 0)
	{
		data->buffer[pixel + 0] = (color) & 0xFF;
		data->buffer[pixel + 1] = (color >> 8) & 0xFF;
		data->buffer[pixel + 2] = (color >> 16) & 0xFF;
		data->buffer[pixel + 3] = (color >> 24);
	}
}

int	gradate_color(int depth, int start_color, int end_color, t_colors *colors)
{
	float	percentage;

	percentage = (float) depth / MAX_DEPTH;
	colors->start_red_value = (start_color >> 16) & 0xFF;
	colors->start_green_value = (start_color >> 8) & 0xFF;
	colors->start_blue_value = (start_color) & 0xFF;
	colors->end_red_value = (end_color >> 16) & 0xFF;
	colors->end_green_value = (end_color >> 8) & 0xFF;
	colors->end_blue_value = (end_color) & 0xFF;
	colors->red_value = colors->start_red_value + 
		(int) (colors->end_red_value - colors->start_red_value) * percentage;
	colors->green_value = colors->start_green_value + 
		(int) (colors->end_green_value - colors->start_green_value) * percentage;
	colors->blue_value = colors->start_blue_value + 
		(int) (colors->end_blue_value - colors->start_blue_value) * percentage;
	return ((colors->red_value << 16) + (colors->green_value << 8) + colors->blue_value);
}

int convert_depth_to_color(int depth, t_mlx *data)
{
	t_colors	colors;
	int			color;

	if (depth == MAX_DEPTH)
		color = INSIDE_COLOR;
	else
		color = gradate_color(depth, OUTSIDE_COLOR, TARGET_COLOR, &colors);
	if (data->pixel_bits != 32)
		color = mlx_get_color_value(data->mlx, color);
	return (color);
}

int	calc_julia(t_mlx *data, double c_re, double c_im)
{
	int depth;
	double z_re;
	double z_im;

	z_re = 0;
	z_im = 0;
	depth = 0;
	return (depth);
}

int	calc_mandelbrot(t_mlx *data, double c_re, double c_im)
{
	int depth;
	double z_re;
	double z_im;
	double tmp;

	z_re = 0;
	z_im = 0;
	depth = 0;
	while (depth < MAX_DEPTH)
	{
		if (z_re * z_re + z_im * z_im > 4.f)
			break;
		tmp = z_im;
		z_im = 2.f * z_re * z_im + c_im;
		z_re = z_re * z_re - tmp * tmp + c_re;
		depth++;
	}
	return (depth);
}

int calc_depth(t_mlx *data, int fractol_type, double z_re, double z_im)
{
	int	depth;

	depth = 0;
	if (fractol_type == MANDELBROT)
	{
		depth = calc_mandelbrot(data, z_re, z_im);
	}
	else if (fractol_type == JULIA)
		depth = calc_julia(data, z_re, z_im);
	return (depth);
}

void	render_fractol(t_mlx *data, int fractol_type)
{
	int		x;
	int		y;
	double	z_re;
	double	z_im;
	int		depth;

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
}