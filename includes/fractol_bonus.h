/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/27 15:05:18 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 12:20:20 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

// Includes..:
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

//// Macros..:
// Common Macros
# define ERR_MAL		"Errors with malloc"
# define ERR_MAN		"Please, enter..:\n\t\"./fractol mandelbrot\"\n"
# define ERR_JUL		"or\n\t\"./fractol julia <value_1> <value_2>\"\n"
# define ERR_PCV		"or\n\t\"./fractol psyclover\"\n"
# define STD_ERR		2
# define ERR_COD		1
# define SCC_COD		0
# define FR_MYN			"psyclover"
# define FR_MYL			9
// Window Tweaking
# define HIGH			800
# define WIDE			800
# define INIT_ZOOM		1.0
# define FRACTAL_QUALITY	42
# define ZOOM_KY		2.0
# define ZOOM_MSO		1.05
# define ZOOM_MSI		0.95
# define MOVE_X			0.5
# define MOVE_Y			0.5
# define MOVE_CURSOR		0.075
// Color Macros
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define PSYCHEDELIC_PURPLE	0x660066
/* Colors Drawer
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define MAGENTA_BURST		0xFF00FF
# define LIME_SHOCK		0xCCFF00
# define NEON_ORANGE		0xFF6600
# define AQUA_DREAM		0x33CCCC
# define HOT_PINK		0xFF66B2
# define ELETRIC_BLUE		0x0066FF
# define LAVA_RED		0xFF3300
*/

// Struct Defines..:
typedef struct s_cnu
{
	double	x;
	double	y;
}	t_cnu;

typedef struct s_img
{
	int		line_len;
	int		endian;
	int		bpp;
	char	*pixels_ptr;
	void	*img_ptr;
}	t_img;

typedef struct s_fractal
{
	int		quality;
	char	*name;
	double	cus_x;
	double	cus_y;
	double	scp_value;
	double	shift_x;
	double	shift_y;
	double	loc_zoom_x;
	double	loc_zoom_y;
	double	zoom;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}	t_fractal;

//// Function files..:
/// Core Function Files..:
// main.c		(1 static)
int		main(int argc, char *argv[]);
// core_init.c		(3 tatic)
void	fractal_init(t_fractal *fractal);
// core_render.c	(3 static)
void	fractal_render(t_fractal *fractal);
// ft_events.c
int		close_handler(t_fractal *fractal);
int		key_handler(int keysym, t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
int		mouse_track(int x, int y, t_fractal *fractal);

/// Util Function Files..:
// ft_math_utils.c
double	scale_map(double u_num, double n_min, double n_max, double o_max);
t_cnu	sum_c(t_cnu z1, t_cnu z2);
t_cnu	sqr_c(t_cnu z1, int abs);

// ft_string_utils.c
void	ft_putstr_fd(char *str, int fd);
double	atodbl(char *s);
int		ft_strncmp(char *s1, char *s2, int n);

#endif
