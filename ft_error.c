/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:35:45 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/24 14:59:27 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putstr("\x1b[31mError fractol\n");
	exit(0);
}

void	ft_usage(void)
{
	ft_putstr("\x1b[32musage: ./fractol [fractol]\n\x1b[0m");
	ft_putstr("\x1b[32mSelect fractol:\n\x1b[0m");
	ft_putstr("\x1b[32mj - Julia\nm - Mandelbrot\nn - Newton\n\x1b[0m");
	ft_putstr("\x1b[32mb - Burning Ship\n\x1b[0m");
	exit(0);
}
