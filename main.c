/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:35:25 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 01:46:11 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_mlx(t_mlx *data, char *fractol, int fractol_type)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, fractol);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->buffer = mlx_get_data_addr(data->image, &data->pixel_bits,
										&data->line_bytes, &data->endian);
	if (fractol_type == MANDELBROT)
	{
		data->max_re = MAX_RE_MANDELBROT;
		data->min_re = MIN_RE_MANDELBROT;
		data->max_im = MAX_IM_MANDELBROT;
		data->min_im = MIN_IM_MANDELBROT;
	}
	mlx_clear_window(data->mlx, data->win);
}

int main(int argc, char **argv)
{
	int		fractol_type;
	t_mlx	data;

	fractol_type = check_args(argc, argv);
	if (fractol_type == INVALID)
		return (show_usage());
	init_mlx(&data, argv[1], fractol_type);
	render_fractol(&data, fractol_type);
	mlx_put_image_to_window(data.mlx, data.win, data.image, 0, 0);
	mlx_loop(data.mlx);
}