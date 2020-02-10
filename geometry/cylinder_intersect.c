/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:14:08 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:29:47 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int				cylinder_intersect(t_cylinder cy, t_ray ray, double *t)
{
	t_equation	e;
	t_vec		pos;

	pos = vec_diff(ray.org, cy.point);
	e.a = (ray.dir.x * ray.dir.x) + (ray.dir.z * ray.dir.z);
	e.b = (2 * ray.org.x * ray.dir.x) + (2 * pos.z * ray.dir.z);
	e.c = (pos.x * pos.x) + (pos.z * pos.z) - cy.diameter;
	e.delta = pow(e.b, 2) - 4 * e.a * e.c;
	if (e.delta < 0)
		return (0);
	else
	{
		e.s0 = (-e.b - sqrt(e.delta)) / 2 * e.a;
		e.s1 = (-e.b + sqrt(e.delta)) / 2 * e.a;
		if (e.s1 > 0)
			*t = e.s0;
		else if (e.s0 > 0)
			*t = e.s1;
		else
			return (0);
		return (1);
	}
}
