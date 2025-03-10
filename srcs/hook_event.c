/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:38:31 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/09 20:38:32 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "rendering.h"
#include "foundation.h"
#include "mlx.h"

int	destroy_event(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.img_ptr);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
}

int	mouse_hook_event(int key, int x, int y, t_engine *engine)
{
	t_fractal	*fract;

	fract = &engine->fractal;
	if (key == MOUSE_SCRL_DOWN)
	{
		fract->offset_x = (x / fract->zoom + fract->offset_x)
			- (x / (fract->zoom * 1.3));
		fract->offset_y = (y / fract->zoom + fract->offset_y)
			- (y / (fract->zoom * 1.3));
		fract->zoom *= 1.3;
		if (fract->iterations < MAX_ITERATIONS)
			++fract->iterations;
	}
	else if (key == MOUSE_SCRL_UP)
	{
		fract->offset_x = (x / fract->zoom + fract->offset_x)
			- (x / (fract->zoom / 1.3));
		fract->offset_y = (y / fract->zoom + fract->offset_y)
			- (y / (fract->zoom / 1.3));
		fract->zoom /= 1.3;
		if (fract->iterations > MIN_ITERATIONS)
			--fract->iterations;
	}
	drawing(engine);
	return (0);
}

int	key_hook_event(int key, t_engine *engine)
{
	if (key >= KEY_Q && key <= KEY_Y)
		change_color(key, engine);
	else if (key >= KEY_ONE && key <= KEY_FOUR)
		key_fractal(key, engine);
	else if (key == KEY_L && engine->fractal.type == JULIA)
		engine->fractal.is_julia_lock ^= 1;
	else if (key == KEY_ZERO)
		reset(engine, engine->fractal.type);
	else if (key == KEY_ESC)
		destroy_event(engine);
	drawing(engine);
	return (0);
}

int	mousemove_event(int x, int y, t_engine *engine)
{
	if (!(engine->fractal.type == JULIA) || engine->fractal.is_julia_lock)
		return (0);
	engine->fractal.mouse_x = x;
	engine->fractal.mouse_y = y;
	drawing(engine);
	return (0);
}
