/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 11:25:16 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/17 20:25:25 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static void		init_res(t_result *res)
{
	res->color = rgb(0, 0, 0);
	res->flag = 0;
	res->sol = 0;
}

t_result		check_intersections(t_object *lst, t_ray ray)
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
		check_object(*lst,ray, &solution, &res);
		// printf("color : %d\n", rgb_to_int(res.color));
		if (solution < min)
		{
			// printf("color : %d\n",res.color.r);
			min = solution;
			final = res;
		}
		lst = lst->next;
	}
	return  (final);
}
