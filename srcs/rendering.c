/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:30:38 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/08 23:30:39 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	change_color(int key, t_engine *engine)
{
	if (key == KEY_Q)
		engine->fractal.color += 0x300000;
	else if (key == KEY_W)
		engine->fractal.color += 0x030000;
	else if (key == KEY_E)
		engine->fractal.color += 0x003000;
	else if (key == KEY_R)
		engine->fractal.color += 0x000300;
	else if (key == KEY_T)
		engine->fractal.color += 0x000030;
	else if (key == KEY_Y)
		engine->fractal.color += 0x000003;
}

void	set_color(t_engine *engine, int x, int y, int color)
{
	int	line_len;
	int	pixel;
	int	offset;

	if (x < 0 || x >= WIN_SIZE || y < 0 || y >= WIN_SIZE)
		return ;
	line_len = engine->image.line_len;
	pixel = engine->image.pixel_bits;
	offset = (y * line_len) + ((pixel / 8) * x);
	*(unsigned int *)(engine->image.addr_ptr + offset) = color;
}

int	fractal_op(t_fractal *fract, t_complex *c, int x, int y)
{
	int	i;

	i = 0;
	if (fract->type != JULIA)
		c->im = (y / fract->zoom) + fract->offset_y;
	else if (!fract->is_julia_lock)
		c->im = (fract->mouse_y / fract->zoom) + fract->offset_y;
	if (fract->type == MANDELBROT)
		i = mandelbrot_op(fract, c);
	else if (fract->type == JULIA)
		i = julia_op(fract, c, x, y);
	return (i);
}

void	drawing(t_engine *engine)
{
	static t_complex	c;
	t_fractal			*fract;
	int					i;
	int					x;
	int					y;

	x = -1;
	fract = &engine->fractal;
	mlx_clear_window(engine->mlx, engine->window);
	while (++x < WIN_SIZE)
	{
		y = -1;
		if (fract->type != JULIA)
			c.re = (x / fract->zoom) + fract->offset_x;
		else if (!fract->is_julia_lock)
			c.re = (fract->mouse_x / fract->zoom) + fract->offset_x;
		while (++y < WIN_SIZE)
		{
			i = fractal_op(fract, &c, x, y);
			set_color(engine, x, y, (i * engine->fractal.color));
		}
	}
	mlx_put_image_to_window(engine->mlx, engine->window, \
		engine->image.img_ptr, 0, 0);
}
