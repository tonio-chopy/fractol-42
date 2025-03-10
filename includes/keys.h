/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:07:03 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/10 01:27:25 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__

enum e_keys
{
	KEY_ESC = 65307,
	KEY_ZERO = 48,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_THREE = 51,
	KEY_FOUR = 52,
	KEY_FIVE = 53,
	KEY_Q = 113,
	KEY_W = 119,
	KEY_E = 101,
	KEY_R = 114,
	KEY_T = 116,
	KEY_Y = 121,
	KEY_L = 108,
	MOUSE_LEFT_CLK = 1,
	MOUSE_SCRL_CLK = 2,
	MOUSE_RIGHT_CLK = 3,
	MOUSE_SCRL_UP = 4,
	MOUSE_SCRL_DOWN = 5,
};

# else

enum e_keys
{
	KEY_ESC = 53,
	KEY_ZERO = 29,
	KEY_ONE = 18,
	KEY_TWO = 19,
	KEY_THREE = 20,
	KEY_FOUR = 21,
	KEY_FIVE = 23,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_R = 15,
	KEY_T = 17,
	KEY_Y = 16,
	KEY_L = 37,
	MOUSE_LEFT_CLK = 1,
	MOUSE_RIGHT_CLK = 2,
	MOUSE_SCRL_CLK = 3,
	MOUSE_SCRL_DOWN = 4,
	MOUSE_SCRL_UP = 5,
};
# endif

#endif
