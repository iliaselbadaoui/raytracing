/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 10:44:41 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/13 12:46:09 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int			plane_intersect(t_plane plane, t_ray ray, double *t)
{
	t_vec		in_plan;
	double		dot;
	
	dot = vec_dot(ray.dir, plane.normal);
	if (dot > 1e-6)
	{
		in_plan = vec_diff(plane.point, ray.org);
		(*t) = vec_dot(normalize_vect(in_plan), plane.normal) / dot;
		return (*t >= 0);
	}
	return (0);
}
