/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:08:07 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:51:16 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	free_camera_utility(t_camera *cam, int code)
{
	free(cam);
	errcode(code);
}

t_generic	fill_camera(t_string *props)
{
	t_generic	cam;

	if (object_props_count(props) != 3)
		errcode(1);
	cam.cam = (t_camera *)malloc(sizeof(t_camera));
	(cam.cam)->pos = fill_vec(props[0]);
	(cam.cam)->normal = fill_vec(props[1]);
	if (!vec_in_range(-1, cam.cam->normal, 1))
		free_camera_utility(cam.cam, 9);
	if (is_number(props[2]) == 1)
	{
		(cam.cam)->fov = ft_atoi(props[2]);
		if (!is_in_range(0, (cam.cam)->fov, 180))
			free_camera_utility(cam.cam, 7);
	}
	else
		free_camera_utility(cam.cam, 7);
	return (cam);
}
