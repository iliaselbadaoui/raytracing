/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 11:25:16 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:17:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static void		init_res(t_result *res)
{
	res->color = rgb(0, 0, 0);
	res->flag = 0;
	res->sol = 0;
	res->normal = vec_init(0, 0, 0);
	res->point = vec_init(0, 0, 0);
	res->pi = vec_init(0, 0, 0);
}

t_result		check_intersections(t_object *lst, t_ray ray, void *current)
{
	double		min;
	double		solution;
	t_result	res;
	t_result	final;

	min = INFINITY;
	init_res(&res);
	init_res(&final);
	while (lst)
	{
		solution = INFINITY;
		res.current = lst;
		if (current != lst)
			check_object(*lst, ray, &solution, &res);
		if (solution < min)
		{
			min = solution;
			final = res;
		}
		lst = lst->next;
	}
	return (final);
}
