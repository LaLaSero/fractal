/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:47:08 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/27 17:16:59 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia(double z_re_initial, double z_im_initial)
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

int	calc_mandelbrot(double c_re, double c_im)
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

// int calc_original(t_mlx *data, double c_re, double c_im)
// {
// 	int depth;
// 	double z_re;
// 	double z_im;
// 	double tmp;
// 	double a, b, a2, b2, denom;

// 	z_re = 0;
// 	z_im = 0;
// 	depth = 0;
// 	while (depth < MAX_DEPTH)
// 	{
// 		if (z_re * z_re + z_im * z_im > 4.f)
// 			break;
// 		a = z_re;
// 		b = z_im;
// 		a2 = a * a;
// 		b2 = b * b;
// 		denom = a2 + b2;
// 		tmp = z_im;
// 		z_re = a * a2 - 3 * a * b2 + 3 * b2 / denom - 3 * a / denom - b2 * b / denom - 3 * b / denom + (a2 - b2) / (4 * a2 * b2 + (a2 - b2) * (a2 - b2)) + c_re;
// 		z_im = 3 * a2 * b - b * b2 + 3 * a * b2 + 3 * a * b / denom - b2 * b / denom - 3 * a / denom - 2 * a * b / (4 * a2 * b2 + (a2 - b2) * (a2 - b2)) + c_im;
// 		depth++;
// 	}
// 	return (depth);
// }

// int calc_original(t_mlx *data, double c_re, double c_im)
// {
// 	// int depth;
// 	// double z_re;
// 	// double z_im;
// 	// double tmp;

// 	// z_re = 0;
// 	// z_im = 0;
// 	// depth = 0;
// 	// while (depth < MAX_DEPTH)
// 	// {
// 	// 	if (z_re * z_re + z_im * z_im > 4.f)
// 	// 		break;
// 	// 	tmp = z_im;
		
// 	// 	depth++;
// 	// }
// 	return (calc_magnet_fractal(data, 1.0, 0.0, 0.5, 0.5));
// }

#include <math.h>

int calc_original(double c_re, double c_im) {
    int depth;
    double z_re, z_im, z_re_squared, z_im_squared, numerator_re, numerator_im, denominator_re, denominator_im, modulus_squared, temp_re, temp_im;

    // 初期化
    z_re = 0;
    z_im = 0;
    depth = 0;

    while (depth < MAX_DEPTH) {
        // z_n^2 を計算
        z_re_squared = z_re * z_re - z_im * z_im;
        z_im_squared = 2 * z_re * z_im;

        // 分子 (z_n^2 + c - 1)
        numerator_re = z_re_squared + c_re - 1;
        numerator_im = z_im_squared + c_im;

        // 分母 (2*z_n + c - 2)
        denominator_re = 2 * z_re + c_re - 2;
        denominator_im = 2 * z_im + c_im;

        // 分母の絶対値の2乗を計算
        modulus_squared = denominator_re * denominator_re + denominator_im * denominator_im;
        if (modulus_squared == 0) {
            // 分母が0になるのを防ぐ
            break;
        }

        // 全体の漸化式を計算
        temp_re = numerator_re * denominator_re + numerator_im * denominator_im;
        temp_im = numerator_im * denominator_re - numerator_re * denominator_im;
        temp_re /= modulus_squared;
        temp_im /= modulus_squared;

        // z_{n+1} = (漸化式の結果)^2
        z_re = temp_re * temp_re - temp_im * temp_im;
        z_im = 2 * temp_re * temp_im;

        // // 逃避半径をチェック
        if ((z_re * z_re + z_im * z_im) > 4.0) {
            break;
        }

        depth++;
    }

    return depth;
}


// int calc_original(t_mlx *data, double c_re, double c_im)
// {
// 	// int depth;
// 	// double z_re;
// 	// double z_im;
// 	// double tmp;

// 	// z_re = 0;
// 	// z_im = 0;
// 	// depth = 0;
// 	// while (depth < MAX_DEPTH)
// 	// {
// 	// 	if (z_re * z_re + z_im * z_im > 4.f)
// 	// 		break;
// 	// 	tmp = z_im;
		
// 	// 	depth++;
// 	// }
// 	return (calc_magnet_fractal(data, 1.0, 0.0, 0.5, 0.5));
// }
