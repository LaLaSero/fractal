/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:48:23 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 17:15:35 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/include/libft.h"
# include <math.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "config.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		max_re;
	int		min_re;
	int		max_im;
	int		min_im;
	int		fractol_type;
}				t_mlx;

typedef struct	s_colors
{
	int		red_value;
	int		green_value;
	int		blue_value;
	int		start_red_value;
	int		start_green_value;
	int		start_blue_value;
	int		end_red_value;
	int		end_green_value;
	int		end_blue_value;
	float	red;
	float	green;
	float	blue;
}				t_colors;

int		check_args(int argc, char **argv);
int		show_usage(void);
void	render_fractol(t_mlx *data, int fractol_type);
void	paint_plot(t_mlx *data, int x, int y, int color);
int		calc_mandelbrot(t_mlx *data, double c_re, double c_im);
int		calc_julia(t_mlx *data, double z_re_initial, double z_im_initial);
int		gradate_color(int depth, int start_color, int end_color, t_colors *colors);
int		generate_random_color(int depth);
int		generate_pseudo_random_color(int depth, t_colors *colors);
int		convert_depth_to_color(int depth, t_mlx *data);
int		handle_key(int keycode, t_mlx *data);
int		exit_program(t_mlx *data);
int		calc_original(t_mlx *data, double c_re, double c_im);
# ifndef TRUE
# define TRUE 1
# endif

# ifndef FALSE
# define FALSE 0
# endif

# ifndef INVALID
# define INVALID -1
# endif

# ifndef VALID
# define VALID 0
# endif

# ifndef MANDELBROT
# define MANDELBROT 1
# endif

# ifndef JULIA
# define JULIA 2
# endif

# ifndef ORIGINAL
# define ORIGINAL 3
# endif

# ifndef YELLOW
# define YELLOW 0xC6FF1F
# endif

# ifndef BLACK
# define BLACK 0x000000
# endif

# ifndef WHITE
# define WHITE 0xFFFFFF
# endif


#endif