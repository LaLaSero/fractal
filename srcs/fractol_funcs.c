/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:47:08 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 17:45:46 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia(t_mlx *data, double z_re_initial, double z_im_initial)
{
	int depth;
	double z_re;
	double z_im;
	double tmp;

	z_re = z_re_initial;
	z_im = z_im_initial;
	depth = 0;
	while (depth < MAX_DEPTH)
	{
		if (z_re * z_re + z_im * z_im > 4.f)
			break;
		tmp = z_im;
		z_im = 2.f * z_re * z_im + JULIA_DEFAULT_VALUE_IM;
		z_re = z_re * z_re - tmp * tmp + JULIA_DEFAULT_VALUE_RE;
		depth++;
	}
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

int calc_original(t_mlx *data, double c_re, double c_im)
{
	int depth;
	double z_re;
	double z_im;
	double tmp;
	double a, b, a2, b2, denom;

	z_re = 0;
	z_im = 0;
	depth = 0;
	while (depth < MAX_DEPTH)
	{
		if (z_re * z_re + z_im * z_im > 4.f)
			break;
		a = z_re;
		b = z_im;
		a2 = a * a;
		b2 = b * b;
		denom = a2 + b2;
		tmp = z_im;
		z_re = a * a2 - 3 * a * b2 + 3 * b2 / denom - 3 * a / denom - b2 * b / denom - 3 * b / denom + (a2 - b2) / (4 * a2 * b2 + (a2 - b2) * (a2 - b2)) + c_re;
		z_im = 3 * a2 * b - b * b2 + 3 * a * b2 + 3 * a * b / denom - b2 * b / denom - 3 * a / denom - 2 * a * b / (4 * a2 * b2 + (a2 - b2) * (a2 - b2)) + c_im;
		depth++;
	}
	return (depth);
}