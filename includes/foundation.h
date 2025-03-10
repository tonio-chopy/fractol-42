/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foundation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:23:59 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/09 22:24:01 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOUNDATION_H
# define FOUNDATION_H

# include "fractal.h"

void	key_fractal(int key, t_engine *engine);
void	set_fractal(t_engine *engine, char *str);
void	reset(t_engine *engine, int fractal_type);
void	init_bro(t_engine *engine, char *arg);

#endif
