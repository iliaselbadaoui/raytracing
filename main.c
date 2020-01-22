/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:24:47 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/17 17:48:45 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int main(int argc, char **argv)
// {
// 	t_resolution	r;
// 	t_camera		cam;
// 	t_mlx			mlx;

// 	r.height = 768;
// 	r.width = 1366;
// 	cam.pos = vec_init(0, 0, 1);
// 	cam.fov = 60;
// 	cam.normal = vec_init(0,0,1);
// 	mlx.mlx = mlx_init();
// 	mlx.img = mlx_new_image(mlx.mlx, r.width, r.height);
// 	mlx.win = mlx_new_window(mlx.mlx, r.width, r.height, "miniRT");
// 	raytracer(cam, r, mlx);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
// 	manage_window(mlx);
// 	mlx_loop(mlx.mlx);
// 	return (0);
// }

int		main(int argc, t_string *argv)
{
	t_object	*lst;

	if (argc < 2 || argc > 3)
		errcode(10);
	else if (!check_args(argc, argv))
		errcode(11);
	else
	{
		lst = reader(argv[1]);
		if (!g_flag.resolution)
		{
			clear_object_list(&lst);
			errcode(12);
		}
		init_data(lst);
		raytracer(lst);
		mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win, g_data.mlx.img, 0, 0);
		manage_window(g_data.mlx);
		mlx_loop(g_data.mlx.mlx);
	}
	return (SUCCESS);
}
