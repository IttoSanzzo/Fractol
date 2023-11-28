/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_events_bonus.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/27 18:13:39 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 12:24:42 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(SCC_COD);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (MOVE_X * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (MOVE_X * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (MOVE_Y * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (MOVE_Y * fractal->zoom);
	else if (keysym == XK_equal)
		fractal->quality += ZOOM_KY;
	else if (keysym == XK_minus)
		fractal->quality -= ZOOM_KY;
	fractal_render(fractal);
	return (0);
}

static void	fractal_zoom_cursor(t_fractal *fractal)
{
	if (fractal->loc_zoom_x < 0.0)
		fractal->shift_x -= (MOVE_CURSOR * fractal->zoom);
	if (fractal->loc_zoom_x > 0.0)
		fractal->shift_x += (MOVE_CURSOR * fractal->zoom);
	if (fractal->loc_zoom_y < 0.0)
		fractal->shift_y -= (MOVE_CURSOR * fractal->zoom);
	if (fractal->loc_zoom_y > 0.0)
		fractal->shift_y += (MOVE_CURSOR * fractal->zoom);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void) x;
	(void) y;
	if (button == Button5 || button == Button4)
		fractal_zoom_cursor(fractal);
	if (button == Button5)
		fractal->zoom *= ZOOM_MSO;
	if (button == Button4)
		fractal->zoom *= ZOOM_MSI;
	fractal_render(fractal);
	return (0);
}

int	mouse_track(int x, int y, t_fractal *fractal)
{
	fractal->loc_zoom_x = scale_map(x, -2, +2, WIDE - 1);
	fractal->loc_zoom_y = scale_map(y, +2, -2, HIGH - 1);
	return (0);
}
