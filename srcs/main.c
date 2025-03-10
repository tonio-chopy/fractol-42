/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:47:41 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/08 21:47:43 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "foundation.h"
#include "rendering.h"
#include "events.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_engine	engine;

	if (ac != 2)
		show_usage();
	init_bro(&engine, av[1]);
	drawing(&engine);
	mlx_key_hook(engine.window, key_hook_event, &engine);
	mlx_mouse_hook(engine.window, mouse_hook_event, &engine);
	mlx_hook(engine.window, 6, 1L << 6, mousemove_event, &engine);
	mlx_hook(engine.window, 17, 0, destroy_event, &engine);
	mlx_loop(engine.mlx);
	return (0);
}
