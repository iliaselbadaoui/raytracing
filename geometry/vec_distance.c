/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 10:34:14 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/23 15:01:35 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double		vec_distance(t_vec v1, t_vec v2)
{
	double x;
	double y;
	double z;

	x = pow(v1.x - v2.x, 2);
	y = pow(v1.y - v2.y, 2);
	z = pow(v1.z - v2.z, 2);
	return (sqrt(x + y + z));
}
