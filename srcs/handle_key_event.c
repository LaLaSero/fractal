/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:17:32 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 18:55:28 by yutakagi         ###   ########.fr       */
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

void	zoom(t_mlx *data, double mag)
{
	double	re_width;
	double	im_height;

	re_width = (data->max_re - data->min_re);
	im_height = (data->max_im - data->min_im);
	data->min_re += re_width * (1.0 - mag) / 2.0;
	data->max_re -= re_width * (1.0 - mag) / 2.0;
	data->min_im += im_height * (1.0 - mag) / (2.0);
	data->max_im -= im_height * (1.0 - mag) / (2.0);
	
}

int	handle_key(int keycode, t_mlx *data)
{
	if (keycode == XK_Escape)
		exit_program(data);
	else if (keycode == XK_space)
		zoom(data, 0.5);
	else if (keycode == XK_minus)
		zoom(data, 2.0);
	render_fractol(data, data->fractol_type);
	return (0);
}
