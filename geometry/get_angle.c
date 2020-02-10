/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:11:31 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:25:37 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double		get_angle(t_vec unit, t_vec v)
{
	double	cosin;

	cosin = vec_dot(unit, v) / vec_distance(g_data.cam->pos, v);
	return (acos(cosin));
}
