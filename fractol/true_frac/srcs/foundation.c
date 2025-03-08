/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foundation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:18:22 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/08 22:18:23 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "foundation.h"
#include "utils.h"
#include "mlx.h"

void  reset(t_engine *engine, int fractal_type)
{
  engine->fractal.type = fractal_type;
  engine->fractal.zoom = WINDOW_SIZE / 4;
  engine->fractal.mouse_x = 0;
  engine->fractal.mouse_y = 0;
  engine->fractal.offset_x = -2;
  engine->fractal.offset_y = -2;
  engine->fractal.is_julia_lock = false;
  engine->fractal.color = DEFAULT_COLOR;
  engine->fractal.iterations = MIN_ITERATIONS;
}

void  key_fractal(int key, t_engine *engine)
{
  reset(engine, MANDELBROT);
  if (key == KEY_TWO)
    engine->fractal.type = JULIA;
  else if (key == KEY_THREE)
      engine->fractal.type = MANDELBROT;
 }

void  set_fractal(t_engine *engine, char *str)
{
  size_t len;

  if(!engine || !str)
    return ;
  ft_strlower(str);
  len = ft_strlen(str);
  if (ft_strncmp(str, MANDELBROT_STR, len) == 0)
    engine->fractal.type = MANDELBROT;
  else if (ft_strncmp(str, JULIA_STR, len) == 0)
      engine->fractal.type = JULIA;
  else
    show_usage();
}

void  init_bro(t_engine *engine, char *arg)
{
  int pixel;
  int line_len;
  int endian;
  
  if (!engine || !arg)
    return ;
  reset(engine, MANDELBROT);
  set_fractal(engine, arg);
  engine->mlx = mlx_init();
  if (!engine->mlx)
    error("can't do mlx_init bro :(\n", 1);
  engine->window = mlx_new_window(engine->mlx, WINDOW_SIZE, WINDOW_SIZE, \
                                  "Fractol 42.");
  engine->image.img_ptr = mlx_new_image(engine->mlx, WINDOW_SIZE, WINDOW_SIZE);
  if (!engine->window || !engine->image.img_ptr)
  {
    mlx_destroy_image(engine->mlx, engine->image.img_ptr);
    mlx_destroy_window(engine->mlx, engine->window);
    error("can't create object bro :(\n", 1);
  }
  engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr, \
                                             &pixel, &line_len, &endian);
  engine->image.pixel_bits = pixel;
  engine->image.line_len = line_len;
  engine->image.endian = endian;
}
