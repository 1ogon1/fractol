/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:12:03 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/23 15:10:37 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*func_4(void *data)
{
	t_env *e;

	e = (t_env *)data;
	if (ft_strcmp(e->c, "j") == 0)
		julia(e, 800);
	else if (ft_strcmp(e->c, "m") == 0)
		mandelbrot(e, 800);
	else if (ft_strcmp(e->c, "n") == 0)
		newton(e, 800);
	else if (ft_strcmp(e->c, "b") == 0)
		burning_ship(e, 800);
	return (0);
}

static void	*func_3(void *data)
{
	t_env *e;

	e = (t_env *)data;
	if (ft_strcmp(e->c, "j") == 0)
		julia(e, 600);
	else if (ft_strcmp(e->c, "m") == 0)
		mandelbrot(e, 600);
	else if (ft_strcmp(e->c, "n") == 0)
		newton(e, 600);
	else if (ft_strcmp(e->c, "b") == 0)
		burning_ship(e, 600);
	return (0);
}

static void	*func_2(void *data)
{
	t_env *e;

	e = (t_env *)data;
	if (ft_strcmp(e->c, "j") == 0)
		julia(e, 400);
	else if (ft_strcmp(e->c, "m") == 0)
		mandelbrot(e, 400);
	else if (ft_strcmp(e->c, "n") == 0)
		newton(e, 400);
	else if (ft_strcmp(e->c, "b") == 0)
		burning_ship(e, 400);
	return (0);
}

static void	*func_1(void *data)
{
	t_env *e;

	e = (t_env *)data;
	if (ft_strcmp(e->c, "j") == 0)
		julia(e, 200);
	else if (ft_strcmp(e->c, "m") == 0)
		mandelbrot(e, 200);
	else if (ft_strcmp(e->c, "n") == 0)
		newton(e, 200);
	else if (ft_strcmp(e->c, "b") == 0)
		burning_ship(e, 200);
	return (0);
}

void		create_fract(t_env *e)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;

	pthread_create(&thread1, NULL, func_1, (void *)e);
	pthread_create(&thread2, NULL, func_2, (void *)e);
	pthread_create(&thread3, NULL, func_3, (void *)e);
	pthread_create(&thread4, NULL, func_4, (void *)e);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
}
