/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:54:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/17 20:27:34 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

void	check_object(t_object lst, t_ray ray, double *solution, t_result *res)
{
	double		t;

	t = INFINITY;
	if (equals(lst.type, "sp"))
	{
		res->flag = spher_intersect(*(lst.content.sp), ray, solution);
		res->color = lst.content.sp->color;
		res->sol = *solution;
	}
	else if (equals(lst.type, "pl"))
	{
		res->flag = plane_intersect(*(lst.content.plane), ray, solution);
		res->color = (*(lst.content.plane)).color;
		res->sol = *solution;
	}
}