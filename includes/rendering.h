/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:24:20 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/09 22:24:22 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "fractal.h"

void	set_color(t_engine *engine, int x, int y, int color);
void	change_color(int key, t_engine *engine);
int		fractal_op(t_fractal *fract, t_complex *c, int x, int y);
void	drawing(t_engine *engine);

#endif
