/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:12:57 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 10:22:02 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/include/ft_printf.h"
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 960
# define HEIGHT 540
# define MAX_ITERATIONS 100
# define INITIAL_ZOOM 1.0
# define COLOR_SHIFT_SPEED 10

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32

# define FRACT_JULIA 'j'
# define FRACT_MANDELBROT 'm'
# define FRACT_FERN 'f'

# define KEY_Z 122
# define ZOOM_SPEED 0.02
# define MAX_ZOOM 500.0
# define MIN_ZOOM 0.5

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	t_complex	c;
	double		zoom;
	double		center_x;
	double		center_y;
	char		fractal_type;
	int			color_shift;
	int			auto_zoom;
	int			zoom_direction;
	int			animate_colors;
}				t_data;

t_complex		complex_square(t_complex z);
t_complex		complex_add(t_complex z1, t_complex z2);
double			complex_abs_squared(t_complex z);
int				julia_iterations(t_complex z, t_complex c);
int				mandelbrot_iterations(t_complex c);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				get_color(int iterations, t_data *data);
void			draw_barnsley_fern(t_data *data);
void			draw_julia(t_data *data);
void			draw_mandelbrot(t_data *data);
void			redraw(t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);
int				key_hook(int keycode, t_data *data);
int				close_window(t_data *data);
int				animate_colors(t_data *data);
void			init_fractal_data(t_data *data, char fractal_type);
void			setup_hooks(t_data *data);
int				auto_zoom(t_data *data);
void			toggle_auto_zoom(t_data *data);
void			clean_exit(t_data *data);
double			ft_atof(const char *str);

#endif