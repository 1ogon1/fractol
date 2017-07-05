/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:03:04 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/24 15:40:48 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_iter(int keykode, t_env *e)
{
	if (keykode == 78)
		e->change->ch_zoom -= 1;
	if (keykode == 69)
		e->change->ch_zoom += 1;
	if (keykode == 27)
		e->change->ch_iter -= 100;
	if (keykode == 24)
		e->change->ch_iter += 100;
	if (e->change->ch_iter <= 100)
		e->change->ch_iter = 100;
	if (e->change->ch_iter >= 1000)
		e->change->ch_iter = 1000;
	if (keykode == 36)
	{
		if (e->enter == 0)
			e->enter = 1;
		else if (e->enter == 1)
			e->enter = 0;
	}
}

static void	move_color(int keykode, t_env *e)
{
	if (keykode == 123)
		e->change->ch_mvx += 0.1;
	if (keykode == 124)
		e->change->ch_mvx -= 0.1;
	if (keykode == 125)
		e->change->ch_mvy -= 0.1;
	if (keykode == 126)
		e->change->ch_mvy += 0.1;
	if (keykode == 12)
		e->change->ch_color += 1;
	if (keykode == 13)
		e->change->ch_color -= 1;
	if (keykode == 45)
		e->col += 5;
	if (keykode == 46)
		e->col -= 5;
	if (keykode == 15)
		e->red = (e->red == 0 ? 1 : 0);
	if (keykode == 5)
		e->green = (e->green == 0 ? 1 : 0);
	if (keykode == 11)
		e->blue = (e->blue == 0 ? 1 : 0);
}

void		change_fract(int keykode, t_env *e)
{
	if (keykode == 18)
	{
		e->c = "j";
		ft_null_ch(e->change, e);
	}
	if (keykode == 19)
	{
		e->c = "m";
		ft_null_ch(e->change, e);
	}
	if (keykode == 20)
	{
		e->c = "n";
		ft_null_ch(e->change, e);
	}
	if (keykode == 21)
	{
		e->c = "b";
		ft_null_ch(e->change, e);
	}
}

int			key_init(int keykode, t_env *e)
{
	if (keykode == 53)
		exit(0);
	if (keykode == 18 || keykode == 19 || keykode == 20 || keykode == 21)
		change_fract(keykode, e);
	if ((keykode >= 123 && keykode <= 126) || keykode == 12 ||
			keykode == 13 || keykode == 45 || keykode == 15 ||
			keykode == 46 || keykode == 5 || keykode == 11)
		move_color(keykode, e);
	if (keykode == 78 || keykode == 69 || keykode == 27 || keykode == 24 ||
			keykode == 36)
		zoom_iter(keykode, e);
	ft_replaceimg(e);
	return (0);
}
