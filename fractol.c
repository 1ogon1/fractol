/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:37:12 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/25 10:54:26 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel(t_env *e, int x, int y, int i)
{
	if (ft_strcmp(e->c, "n") == 0 || ft_strcmp(e->c, "m") == 0 ||
			ft_strcmp(e->c, "b") == 0)
	{
		e->data[(x * 4) + (y * WIDTH * 4)] = e->blue * ((i * i) + e->col *
				e->col);
		e->data[(x * 4) + (y * WIDTH * 4) + 1] = e->green * (i + e->col);
		e->data[(x * 4) + (y * WIDTH * 4) + 2] = e->red * (i % 256 + e->col *
				e->col);
	}
	else
	{
		e->data[(x * 4) + (y * WIDTH * 4)] = e->blue * (i + e->col * e->col);
		e->data[(x * 4) + (y * WIDTH * 4) + 1] = e->green * (i + e->col);
		e->data[(x * 4) + (y * WIDTH * 4) + 2] = e->red * i;
	}
}

void			ft_null_ch(t_change *c, t_env *e)
{
	e->enter = 0;
	e->col = 0;
	e->red = 1;
	e->blue = 1;
	e->green = 1;
	c->ch_mvx = 0;
	c->ch_mvy = 0;
	c->ch_cre = 0;
	c->ch_cim = 0;
	c->ch_iter = 100;
	c->ch_zoom = 1;
	c->ch_color = 0;
	c->ch_pr = 0;
	c->ch_pi = 0;
}

void			ident_fractal(t_env *e, char *argv)
{
	if (ft_strcmp(argv, "j") == 0)
		e->c = ft_strdup(argv);
	else if (ft_strcmp(argv, "m") == 0)
		e->c = ft_strdup(argv);
	else if (ft_strcmp(argv, "n") == 0)
		e->c = ft_strdup(argv);
	else if (ft_strcmp(argv, "b") == 0)
		e->c = ft_strdup(argv);
	else
		ft_error();
}

static void		open_window(char *argv)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return ;
	if (!(e->change = (t_change *)malloc(sizeof(t_change))))
		return ;
	ident_fractal(e, argv);
	ft_null_ch(e->change, e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1400, 800, "fract'ol");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	ft_menu(e);
	create_fract(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_hook(e->win, 2, 3, key_init, e);
	mlx_hook(e->win, 6, 0, mouse_move, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		open_window(argv[1]);
	else
		ft_usage();
	return (0);
}
