/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:17:16 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/24 16:04:53 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fract	*ft_n_null(t_env *e)
{
	t_fract	*elem;

	if (!(elem = (t_fract *)malloc(sizeof(t_fract))))
		return (0);
	elem->newre = 0;
	elem->newim = 0;
	elem->tmp = 1.0;
	elem->oldre = 0;
	elem->oldim = 0;
	elem->maxit = 100 + e->change->ch_iter;
	elem->zoom = 0.1 + e->change->ch_zoom;
	elem->mvx = 0 + e->change->ch_mvx;
	elem->mvy = 0 + e->change->ch_mvy;
	return (elem);
}

static int		ft_newton(t_fract *f)
{
	int		i;

	i = 0;
	while (f->tmp > 0.000001 && ++i < f->maxit)
	{
		f->oldre = f->newre;
		f->oldim = f->newim;
		f->tmp = (f->newre * f->newre + f->newim * f->newim) *
			(f->newre * f->newre + f->newim * f->newim);
		f->newre = (2 * f->newre * f->tmp + f->newre * f->newre -
				f->newim * f->newim) / (3.0 * f->tmp);
		f->newim = (2 * f->newim * (f->tmp - f->oldre)) / (3.0 * f->tmp);
		f->tmp = (f->newre - f->oldre) * (f->newre - f->oldre) +
			(f->newim - f->oldim) * (f->newim - f->oldim);
	}
	return (i);
}

void			newton(t_env *e, int go_to)
{
	int		x;
	int		y;
	t_fract	*f;

	y = go_to - 200;
	f = ft_n_null(e);
	while (y < go_to)
	{
		x = 0;
		f->tmp = 1.0;
		while (x < WIDTH)
		{
			f->newre = (x - WIDTH / 2) / (f->zoom * WIDTH / 2) + f->mvx;
			f->newim = (y - HEIGHT / 2) / (f->zoom * HEIGHT / 2) + f->mvy;
			f->tmp = 1.0;
			put_pixel(e, x, y, ft_newton(f));
			x++;
		}
		y++;
	}
	free(f);
}
