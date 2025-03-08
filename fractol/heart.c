/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:55:47 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/08 15:55:48 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_heart(t_data *img, int center_x, int center_y, int size, int color)
{
	int x, y;
	float scaled_x, scaled_y;

	for (y = -size; y <= size; y++)
	{
		for (x = -size; x <= size; x++)
		{
			scaled_x = (float)x / size * 2.5f;
			scaled_y = (float)y / size * 2.5f;

			if (pow(scaled_x * scaled_x + scaled_y * scaled_y - 1, 3) - scaled_x * scaled_x * scaled_y * scaled_y * scaled_y <= 0)
			{
				my_mlx_pixel_put(img, center_x + x, center_y - y, color);
			}
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		win_width = 1920;
	int		win_height = 1080;
	int		heart_size = 200;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, win_width, win_height, "Heart");
	img.img = mlx_new_image(mlx, win_width, win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int center_x = win_width / 2;
	int center_y = win_height / 2;

	draw_heart(&img, center_x, center_y, heart_size, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
