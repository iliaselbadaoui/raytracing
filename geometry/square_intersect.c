/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:43:22 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/06 09:17:07 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int				square_intersect(t_square sq, t_ray ray, double *t)
{
	int			res;
	t_triangle	t1;
	t_triangle	t2;

	t1.p1 = sq.p1;
	t1.p2 = sq.p2;
	t1.p3 = sq.p3;
	t2.p1 = sq.p1;
	t2.p2 = sq.p3;
	t2.p3 = sq.p4;
	res = tirangle_intersect(t1, ray, t);
	if (res)
		return (1);
	res = tirangle_intersect(t2, ray, t);
	if (res)
		return (1);
	return (0);
}
