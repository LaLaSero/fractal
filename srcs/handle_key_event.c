/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:17:32 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/27 17:09:56 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_program(t_mlx *data)
{
	if (data->image != NULL)
		mlx_destroy_image(data->mlx, data->image);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}

void	zoom_out(t_mlx *data)
{
	double	re_width;
	double	im_height;

	re_width = (data->max_re - data->min_re);
	im_height = (data->max_im - data->min_im);
	data->min_re -= re_width / 4.0;
	data->max_re += re_width / 4.0;
	data->min_im -= im_height / 4.0;
	data->max_im += im_height / 4.0;
}

void	zoom_in(t_mlx *data)
{
	double	re_width;
	double	im_height;

	re_width = (data->max_re - data->min_re);
	im_height = (data->max_im - data->min_im);
	data->min_re += re_width / 4.0;
	data->max_re -= re_width / 4.0;
	data->min_im += im_height / 4.0;
	data->max_im -= im_height / 4.0;
}

void	move(t_mlx *data, int direction)
{
	double	dist_re;
	double	dist_im;

	dist_re = (data->max_re - data->min_re) / 5.0;
	dist_im = (data->max_im - data->min_im) / 5.0;
	if (direction == UP)
	{
		data->min_im += dist_im;
		data->max_im += dist_im;
	}
	else if (direction == DOWN)
	{
		data->min_im -= dist_im;
		data->max_im -= dist_im;
	}
	else if (direction == LEFT)
	{
		data->min_re += dist_re;
		data->max_re += dist_re;
	}
	else if (direction == RIGHT)
	{
		data->min_re -= dist_re;
		data->max_re -= dist_re;
	}
}

int	handle_key(int keycode, t_mlx *data)
{
	if (keycode == XK_Escape)
		exit_program(data);
	else if (keycode == XK_space)
		zoom_in(data);
	else if (keycode == XK_minus)
		zoom_out(data);
	else if (keycode == XK_Up)
		move(data, UP);
	else if (keycode == XK_Down)
		move(data, DOWN);
	else if (keycode == XK_Left)
		move(data, LEFT);
	else if (keycode == XK_Right)
		move(data, RIGHT);
	render_fractol(data, data->fractol_type);
	return (0);
}
