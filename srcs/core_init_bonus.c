/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   core_init_bonus.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/27 16:11:21 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 11:26:59 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	malloc_error(void)
{
	perror(ERR_MAL);
	exit(ERR_COD);
}

static void	data_init(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, FR_MYN, FR_MYL))
	{
		fractal->cus_x = 0.38;
		fractal->cus_y = -0.58;
	}
	fractal->scp_value = 4;
	fractal->zoom = INIT_ZOOM;
	fractal->quality = FRACTAL_QUALITY;
	fractal->loc_zoom_x = 0;
	fractal->loc_zoom_y = 0;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress,
		ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify,
		StructureNotifyMask, close_handler, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify,
		PointerMotionMask, mouse_track, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDE, HIGH, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDE, HIGH);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
