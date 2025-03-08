/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:57:21 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/08 13:57:24 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Ilan giga chad");

    mlx_pixel_put(mlx, win, 400, 300, 0xFFFFFF);

    mlx_loop(mlx);
    return (0);
}
