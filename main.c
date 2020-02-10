/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:24:47 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/10 17:10:18 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		if (!g_flag.resolution || !g_flag.camera)
			errcode(12);
		init_data(lst, argv[2]);
		g_object = lst;
		g_data.lst = get_light_list(lst);
		raytracer(lst);
		if (equals(argv[2], "--save"))
			return (save_to_bitmap());
		mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win,
		g_data.mlx.img, 0, 0);
		mlx_destroy_image(g_data.mlx.mlx, g_data.mlx.img);
		manage_window(g_data.mlx);
		mlx_loop(g_data.mlx.mlx);
	}
	return (SUCCESS);
}
