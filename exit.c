/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:27:45 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 22:01:55 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			escape(int key)
{
	if (key == 53)
	{
		exit(SUCCESS);
		return (1);
	}
	else if (key == 45)
	{
		get_next_cam(g_object);
		mlx_clear_window(g_data.mlx.mlx, g_data.mlx.win);
		g_data.mlx.img = mlx_new_image(g_data.mlx.mlx, g_data.res.width,
	g_data.res.height);
		raytracer(g_object);
		mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win,
	g_data.mlx.img, 0, 0);
		return (1);
	}
	return (0);
}

int			close_win(int key)
{
	key = 1;
	exit(SUCCESS);
	return (1);
}
