/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:07:33 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:37:48 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "../minirt.h"

static t_rgb	phong_diffuse(t_light light, t_rgb col, double dot, int first)
{
	t_rgb	res;

	if (first)
	{
		res.r = clamp_rgb(0, (col.r + light.color.r) * light.range, 255);
		res.g = clamp_rgb(0, (col.g + light.color.g) * light.range, 255);
		res.b = clamp_rgb(0, (col.b + light.color.b) * light.range, 255);
	}
	else
	{
		res.r = clamp_rgb(0, light.color.r * light.range, 255);
		res.g = clamp_rgb(0, light.color.g * light.range, 255);
		res.b = clamp_rgb(0, light.color.b * light.range, 255);
	}
	dot = max(0, dot);
	res.r *= dot;
	res.g *= dot;
	res.b *= dot;
	return (res);
}

static t_rgb	phong_ambient(t_ambient amb, t_rgb col)
{
	t_rgb	res;

	res.r = clamp_rgb(0, (col.r + amb.color.r) * amb.range, 255);
	res.g = clamp_rgb(0, (col.g + amb.color.g) * amb.range, 255);
	res.b = clamp_rgb(0, (col.b + amb.color.b) * amb.range, 255);
	return (res);
}

void			phong(t_lights *lst, t_result res, t_img_point point)
{
	t_ray	shadow;
	t_vec	hp;
	double	dot;
	t_rgb	col;

	col = rgb(0, 0, 0);
	while (lst)
	{
		hp = vec_add(lst->content->pos, res.pi);
		dot = vec_dot(res.normal, normalize_vect(hp));
		shadow = ray_init(hp, vec_times_double(lst->content->pos, -1));
		if (!(check_intersections(g_object, shadow, res.current).flag))
		{
			if (!rgb_to_int(col) && lst->content->range > 0)
				col = phong_diffuse(*(lst->content), res.color, dot, 1);
			else
				col = add_rgb(col, phong_diffuse(*(lst->content), res.color,
				dot, 0));
		}
		lst = lst->next;
	}
	col = add_rgb(col, phong_ambient(g_data.amb, res.color));
	put_pixel(point.x, point.y, rgb_to_int(col));
}
