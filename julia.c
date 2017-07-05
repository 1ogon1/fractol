/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:34:36 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/25 12:13:51 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fract	*ft_j_null(t_env *e)
{
	t_fract		*new;

	if (!(new = (t_fract *)malloc(sizeof(t_fract))))
		return (0);
	new->maxit = 0 + e->change->ch_iter;
	new->cre = -0.7 + e->change->ch_cre;
	new->cim = 0.27015 + e->change->ch_cim;
	new->newre = 0;
	new->newim = 0;
	new->oldre = 0;
	new->oldim = 0;
	new->mvx = 0 + e->change->ch_mvx;
	new->mvy = 0 + e->change->ch_mvy;
	new->zoom = 1 * e->change->ch_zoom;
	return (new);
}

static int		j_iter(t_fract *f)
{
	int		i;

	i = 0;
	while (i < f->maxit)
	{
		f->oldre = f->newre;
		f->oldim = f->newim;
		f->newre = f->oldre * f->oldre - f->oldim * f->oldim + f->cre;
		f->newim = 2 * f->oldre * f->oldim + f->cim;
		if ((f->newre * f->newre + f->newim * f->newim) > 4)
			break ;
		i++;
	}
	return (i);
}

void			julia(t_env *e, int go_to)
{
	int		x;
	int		y;
	t_fract	*f;

	x = 0;
	y = go_to - 200;
	f = ft_j_null(e);
	while (y < go_to)
	{
		x = 0;
		while (x < WIDTH)
		{
			f->newre = 1.5 * (x - WIDTH / 2) / (f->zoom * WIDTH / 2) + f->mvx;
			f->newim = (y - HEIGHT / 2) / (f->zoom * HEIGHT / 2) + f->mvy;
			put_pixel(e, x, y, j_iter(f));
			x++;
		}
		y++;
	}
	free(f);
}
