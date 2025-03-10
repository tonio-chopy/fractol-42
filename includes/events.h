/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:00:34 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/09 22:00:35 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fractal.h"

int	destroy_event(t_engine *engine);
int	mouse_hook_event(int key, int x, int y, t_engine *engine);
int	key_hook_event(int key, t_engine *engine);
int	mousemove_event(int x, int y, t_engine *engine);

#endif
