/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:00:32 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/24 16:05:26 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fract	*ft_b_null(t_env *e)
{
	t_fract	*elem;

	if (!(elem = (t_fract *)malloc(sizeof(t_fract))))
		return (0);
	elem->oldre = 0;
	elem->oldim = 0;
	elem->tmp = 0;
	elem->newre = 0;
	elem->newim = 0;
	elem->maxit = 100 + e->change->ch_iter;
	elem->zoom = -0.5 + e->change->ch_zoom;
	elem->mvx = -0.3 + e->change->ch_mvx;
	elem->mvy = 0 + e->change->ch_mvy;
	return (elem);
}

static int		ft_burn(t_fract *f)
{
	int		i;

	i = 0;
	while (f->oldre * f->oldre + f->oldim * f->oldim < 4 && ++i < f->maxit)
	{
		f->tmp = f->oldim;
		f->oldim = fabs(f->oldre * f->oldim + f->oldre * f->oldim + f->newim);
		f->oldre = fabs(f->oldre * f->oldre - f->tmp * f->tmp + f->newre);
	}
	return (i);
}

void			burning_ship(t_env *e, int go_to)
{
	int		x;
	int		y;
	t_fract	*f;

	y = go_to - 200;
	f = ft_b_null(e);
	while (y < go_to)
	{
		x = 0;
		while (x < WIDTH)
		{
			f->newre = (x - WIDTH / 2) / (f->zoom * WIDTH / 2) + f->mvx;
			f->newim = (y - HEIGHT / 2) / (f->zoom * HEIGHT / 2) + f->mvy;
			f->oldre = f->newre;
			f->oldim = f->newim;
			put_pixel(e, x, y, ft_burn(f));
			x++;
		}
		y++;
	}
}
