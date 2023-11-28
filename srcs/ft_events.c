/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/27 18:13:39 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 12:24:54 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "fractol.h"

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
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void) x;
	(void) y;
	if (button == Button5)
		fractal->zoom *= ZOOM_MSO;
	else if (button == Button4)
		fractal->zoom *= ZOOM_MSI;
	fractal_render(fractal);
	return (0);
}
