/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:34:10 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/08 21:34:11 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars {
    void    *mlx;
    void    *win;
}               t_vars;

int close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}

int handle_keypress(int keycode, t_vars *vars)
{
    if (keycode == 65307)
        close_window(vars);
    return (0);
}

int handle_resize(int width, int height, t_vars *vars)
{
    (void)vars;
    printf("Nouvelle taille de la fenêtre : %dx%d\n", width, height);
    return (0);
}

int main(void)
{
    t_vars  vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "je t'embrouille chef");

    mlx_hook(vars.win, 17, 0, close_window, &vars);

    mlx_hook(vars.win, 2, 1L<<0, handle_keypress, &vars);

    mlx_hook(vars.win, 22, 1L<<0, (int (*)())handle_resize, &vars);

    mlx_loop(vars.mlx);
    return (0);
}
