/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:24:26 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/09 22:24:29 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractal.h"

void	error(char *text, int mode);
void	ft_strlower(char *str);
void	print(char *str, int fd);
void	show_usage(void);

#endif
