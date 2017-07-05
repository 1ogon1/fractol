/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:04:45 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/24 15:57:20 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1000
# define HEIGHT 800
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include "libft/libft.h"

typedef struct	s_burn
{
	float		zr;
	float		zi;
	float		tmp;
	float		cr;
	float		ci;
	float		mvx;
	float		mvy;
	float		zoom;
	int			maxiter;
}				t_burn;

typedef struct	s_newton
{
	float		zr;
	float		zi;
	float		tmp;
	float		oldre;
	float		oldim;
	float		mvx;
	float		mvy;
	float		zoom;
	int			maxiter;
}				t_newt;

typedef struct	s_julia
{
	int			maxit;
	float		newre;
	float		newim;
	float		oldre;
	float		oldim;
	float		mvx;
	float		mvy;
	float		zoom;
}				t_julia;

typedef struct	s_fract
{
	int			maxit;
	float		cre;
	float		cim;
	float		pr;
	float		pi;
	float		ch_pr;
	float		ch_pi;
	float		newre;
	float		newim;
	float		oldre;
	float		oldim;
	float		mvx;
	float		mvy;
	float		zoom;
	float		tmp;
}				t_fract;

typedef struct	s_change
{
	float		ch_mvx;
	float		ch_mvy;
	float		ch_cre;
	float		ch_cim;
	float		ch_iter;
	float		ch_zoom;
	float		ch_pr;
	float		ch_pi;
	int			ch_color;
}				t_change;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			col;
	int			red;
	int			green;
	int			blue;
	char		*c;
	char		*data;
	int			enter;
	int			bpp;
	int			size_line;
	int			endian;
	t_change	*change;
}				t_env;

void			burning_ship(t_env *e, int go_to);
void			mandelbrot(t_env *e, int go_to);
void			newton(t_env *e, int go_to);
void			julia(t_env *e, int go_to);

void			put_pixel(t_env *e, int x, int y, int i);
void			ft_null_ch(t_change *c, t_env *e);
void			ft_replaceimg(t_env *e);
void			create_fract(t_env *e);
void			ft_menu(t_env *e);
void			ft_error(void);
void			ft_usage(void);

int				mouse_hook(int button, int x, int y, t_env *e);
int				mouse_move(int x, int y, t_env *e);
int				key_init(int keykode, t_env *e);

#endif
