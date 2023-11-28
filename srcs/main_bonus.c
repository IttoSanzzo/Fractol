/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/27 15:18:42 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 02:40:48 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	exit_error(void)
{
	ft_putstr_fd(ERR_MAN, STD_ERR);
	ft_putstr_fd(ERR_JUL, STD_ERR);
	ft_putstr_fd(ERR_PCV, STD_ERR);
	exit(ERR_COD);
}

static void	get_julia(char **argv, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->cus_x = atodbl(argv[2]);
		fractal->cus_y = atodbl(argv[3]);
	}
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (!((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
			|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
			|| (argc == 2 && !ft_strncmp(argv[1], FR_MYN, FR_MYL))))
		exit_error();
	fractal.name = argv[1];
	get_julia(argv, &fractal);
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
