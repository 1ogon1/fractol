/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:12:53 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/24 15:58:27 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fract	*ft_m_null(t_env *e)
{
	t_fract	*new;

	if (!(new = (t_fract *)malloc(sizeof(t_fract))))
		return (0);
	new->maxit = 0 + e->change->ch_iter;
	new->pr = 0;
	new->ch_pr = e->change->ch_pr;
	new->pi = 0;
	new->ch_pi = e->change->ch_pi;
	new->newre = 0;
	new->newim = 0;
	new->oldre = 0;
	new->oldim = 0;
	new->mvx = -0.5 + e->change->ch_mvx;
	new->mvy = 0 + e->change->ch_mvy;
	new->zoom = 1 * e->change->ch_zoom;
	return (new);
}

static int		m_iter(t_fract *f)
{
	int		i;

	i = 0;
	while (i < f->maxit)
	{
		f->oldre = f->newre + f->ch_pr;
		f->oldim = f->newim + f->ch_pi;
		f->newre = f->oldre * f->oldre - f->oldim * f->oldim + f->pr;
		f->newim = 2 * f->oldre * f->oldim + f->pi;
		if ((f->newre * f->newre + f->newim * f->newim) > 4)
			break ;
		i++;
	}
	return (i);
}

void			ft_renull(t_fract *f)
{
	f->newre = 0;
	f->newim = 0;
	f->oldre = 0;
	f->oldim = 0;
}

void			mandelbrot(t_env *e, int go_to)
{
	int		x;
	int		y;
	t_fract	*f;

	x = 0;
	y = go_to - 200;
	f = ft_m_null(e);
	while (y < go_to)
	{
		x = 0;
		while (x < WIDTH)
		{
			f->pr = 1.5 * (x - WIDTH / 2) / (f->zoom * WIDTH / 2) + f->mvx;
			f->pi = (y - HEIGHT / 2) / (f->zoom * HEIGHT / 2) + f->mvy;
			ft_renull(f);
			put_pixel(e, x, y, m_iter(f));
			x++;
		}
		y++;
	}
	free(f);
}
