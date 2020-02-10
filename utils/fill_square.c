/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:39:28 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:51:27 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../geometry/geometry.h"

t_generic		fill_square(t_string *props)
{
	t_generic	res;
	t_vec		e1;
	t_vec		e2;
	t_vec		e3;
	t_vec		e4;

	if (object_props_count(props) != 5)
		errcode(1);
	res.sq = (t_square *)malloc(sizeof(t_square));
	(res.sq)->p1 = fill_vec(props[0]);
	(res.sq)->p2 = fill_vec(props[1]);
	(res.sq)->p3 = fill_vec(props[2]);
	(res.sq)->p4 = fill_vec(props[3]);
	e1 = vec_diff(res.sq->p2, res.sq->p1);
	e2 = vec_diff(res.sq->p4, res.sq->p1);
	e3 = vec_diff(res.sq->p2, res.sq->p3);
	e4 = vec_diff(res.sq->p4, res.sq->p3);
	if (vec_dot(e1, e2) || vec_dot(e3, e4))
	{
		errcode(13);
		free(res.sq);
	}
	(res.sq)->color = fill_rgb(props[4]);
	return (res);
}
