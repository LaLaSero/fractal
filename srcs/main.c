/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:35:25 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 18:24:49 by yutakagi         ###   ########.fr       */
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
	data->fractol_type = fractol_type;
	if (fractol_type == MANDELBROT)
	{
		data->max_re = MAX_RE_MANDELBROT;
		data->min_re = MIN_RE_MANDELBROT;
		data->max_im = MAX_IM_MANDELBROT;
		data->min_im = MIN_IM_MANDELBROT;
	}
	else if (fractol_type == JULIA || fractol_type == ORIGINAL)
	{
		data->max_re = MAX_RE_JULIA;
		data->min_re = MIN_RE_JULIA;
		data->max_im = MAX_IM_JULIA;
		data->min_im = MIN_IM_JULIA;
	}
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
	mlx_hook(data.win, X_BUTTON, 0, exit_program, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop(data.mlx);
}