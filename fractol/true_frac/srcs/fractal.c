/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:36:59 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/09 00:37:01 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "math.h"

int mandelbrot_op(t_fractal *fract, t_complex *c)
{
  double  re_temp;
  t_complex z;
  int       i;

  i = -1;
  z.re = 0;
  z.im = 0;
  while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
  {
    re_temp = z.re * z.re - z,
  }
}
