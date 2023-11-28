/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/27 15:33:21 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 01:57:41 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	while (*str)
		write(fd, &*str++, 1);
}

double	atodbl(char *s)
{
	int		sign;
	long	int_p;
	double	frc_p;
	double	pwr;

	int_p = 0;
	frc_p = 0;
	sign = 1;
	pwr = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s && *s != '.')
		int_p = (int_p * 10) + (*s++ - '0');
	if ('.' == *s)
		s++;
	while (*s)
	{
		pwr /= 10;
		frc_p = frc_p + (*s++ - '0') * pwr;
	}
	return ((int_p + frc_p) * sign);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (*s1 && *s1 == *s2 && n-- > 0)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
