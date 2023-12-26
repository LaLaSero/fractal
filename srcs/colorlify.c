/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorlify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:49:09 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 17:44:15 by yutakagi         ###   ########.fr       */
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

int	generate_random_color(int depth)
{
	int	red_value;
	int	green_value;
	int	blue_value;

	red_value = (depth * 7) % 255;
	green_value = (depth * 9) % 255;
	blue_value = (depth * 11) % 255;
	return ((red_value << 16) + (green_value << 8) + blue_value);
}

int generate_pseudo_random_color(int depth, t_colors *colors)
{
	int	red_value;
	int	green_value;
	int	blue_value;

	colors->red = (sin(depth) + 1) / 2;
	colors->green = (cos(depth) + 1) / 2;
	colors->blue = (tan(depth) + 1) / 2;
	red_value = (int)(colors->red * 255) % 255;
	green_value = (int)(colors->green * 255) % 255;
	blue_value = (int)(colors->blue * 255) % 255;
	return ((red_value << 16) + (green_value << 8) + blue_value);
}

int convert_depth_to_color(int depth, t_mlx *data)
{
	t_colors	colors;
	int			color;

	if (depth == MAX_DEPTH)
		color = INSIDE_COLOR;
	else if (GRADATION == TRUE)
		color = gradate_color(depth, OUTSIDE_COLOR, TARGET_COLOR, &colors);
	else if (PSYCHEDELIC == FALSE)
		color = generate_random_color(depth);
	else
		color = generate_pseudo_random_color(depth, &colors);
	if (data->pixel_bits != 32)
		color = mlx_get_color_value(data->mlx, color);
	return (color);
}