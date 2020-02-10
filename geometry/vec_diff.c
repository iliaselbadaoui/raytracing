/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_diff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:20:57 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/26 20:28:41 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_vec	vec_diff(t_vec v1, t_vec v2)
{
	t_vec res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vec	vec_times_double(t_vec v, double d)
{
	t_vec res;

	res.x = v.x * d;
	res.y = v.y * d;
	res.z = v.z * d;
	return (res);
}

t_vec	vec_devided_double(t_vec v, double d)
{
	t_vec res;

	res.x = v.x / d;
	res.y = v.y / d;
	res.z = v.z / d;
	return (res);
}

t_vec	normalize_vect(t_vec vec)
{
	double coeff;

	coeff = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (vec_devided_double(vec, coeff));
}
