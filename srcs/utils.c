/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:55:01 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/08 21:55:02 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"

void	error(char *txt, int mode)
{
	if (mode == 0)
		perror(txt);
	else if (txt)
		ft_putstr_fd(txt, 2);
	exit(EXIT_FAILURE);
}

void	ft_strlower(char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

void	print(char *str, int fd)
{
	ft_putstr_fd(str, fd);
}

void	show_usage(void)
{
	print("Usage: ./fractol [mandelbrot / julia]\n", 1);
	exit(EXIT_SUCCESS);
}
