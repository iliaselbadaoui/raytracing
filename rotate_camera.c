/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:51:55 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 22:07:34 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	int	rotate_help(int key)
{
	if (key == 0)
	{
		g_data.cam->normal = x_rotation(g_data.cam->normal, -M_PI / 180);
		mlx_clear_window(g_data.mlx.mlx, g_data.mlx.win);
		g_data.mlx.img = mlx_new_image(g_data.mlx.mlx, g_data.res.width,
		g_data.res.height);
		raytracer(g_object);
		mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win,
		g_data.mlx.img, 0, 0);
	}
	else if (key == 2)
	{
		g_data.cam->normal = x_rotation(g_data.cam->normal, M_PI / 180);
		mlx_clear_window(g_data.mlx.mlx, g_data.mlx.win);
		g_data.mlx.img = mlx_new_image(g_data.mlx.mlx, g_data.res.width,
		g_data.res.height);
		raytracer(g_object);
		mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win,
		g_data.mlx.img, 0, 0);
	}
	return (0);
}

int			rotate_camera(int key)
{
	if (key == 13)
	{
		g_data.cam->normal = z_rotation(g_data.cam->normal, M_PI / 180);
		mlx_clear_window(g_data.mlx.mlx, g_data.mlx.win);
		g_data.mlx.img = mlx_new_image(g_data.mlx.mlx, g_data.res.width,
		g_data.res.height);
		raytracer(g_object);
		mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win,
		g_data.mlx.img, 0, 0);
	}
	else if (key == 1)
	{
		g_data.cam->normal = z_rotation(g_data.cam->normal, -M_PI / 180);
		mlx_clear_window(g_data.mlx.mlx, g_data.mlx.win);
		g_data.mlx.img = mlx_new_image(g_data.mlx.mlx, g_data.res.width,
		g_data.res.height);
		raytracer(g_object);
		mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win,
		g_data.mlx.img, 0, 0);
	}
	rotate_help(key);
	return (0);
}
