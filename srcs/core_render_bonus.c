/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   core_render_bonus.c                                :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/27 16:46:53 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 02:27:57 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_putppixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	switch_fractal(t_cnu *z, t_cnu *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5)
		|| (!ft_strncmp(fractal->name, FR_MYN, FR_MYL)))
	{
		c->x = fractal->cus_x;
		c->y = fractal->cus_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	int		color;
	int		i;
	t_cnu	z;
	t_cnu	c;

	i = -1;
	z.x = (scale_map(x, -2, +2, WIDE - 1) * fractal->zoom) + fractal->shift_x;
	z.y = (scale_map(y, +2, -2, HIGH - 1) * fractal->zoom) + fractal->shift_y;
	switch_fractal(&z, &c, fractal);
	while (++i < fractal->quality)
	{
		if (!ft_strncmp(fractal->name, FR_MYN, FR_MYL))
			z = sum_c(sqr_c(z, 1), c);
		else
			z = sum_c(sqr_c(z, 0), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->scp_value)
		{
			color = scale_map(i, BLACK, WHITE, fractal->quality);
			ft_putppixel(x, y, &fractal->img, color);
			return ;
		}
	}
	ft_putppixel(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HIGH)
	{
		x = -1;
		while (++x < WIDE)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
