/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:15:32 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:57:47 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec		x_rotation(t_vec vec, double alpha)
{
	t_vec	res;

	res.x = vec.x;
	res.z = vec.z * cos(alpha) - vec.y * sin(alpha);
	res.y = vec.z * sin(alpha) + vec.y * cos(alpha);
	return (res);
}

t_vec		y_rotation(t_vec vec, double alpha)
{
	t_vec	res;

	res.x = vec.x * cos(alpha) - vec.z * sin(alpha);
	res.z = vec.x * sin(alpha) + vec.z * cos(alpha);
	res.y = vec.y;
	return (res);
}

t_vec		z_rotation(t_vec vec, double alpha)
{
	t_vec	res;

	res.x = vec.x * cos(alpha) - vec.y * sin(alpha);
	res.z = vec.z;
	res.y = vec.x * sin(alpha) + vec.y + cos(alpha);
	return (res);
}
