/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:48:23 by yutakagi          #+#    #+#             */
/*   Updated: 2023/12/26 01:53:18 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "./libft/include/libft.h"
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
}				t_mlx;

typedef struct	s_colors
{
	int	red_value;
	int	green_value;
	int	blue_value;
	int	start_red_value;
	int	start_green_value;
	int	start_blue_value;
	int	end_red_value;
	int	end_green_value;
	int	end_blue_value;
}				t_colors;

int		check_args(int argc, char **argv);
int		show_usage(void);
void	render_fractol(t_mlx *data, int fractol_type);
void	paint_plot(t_mlx *data, int x, int y, int color);


#endif