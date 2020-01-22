/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:39:28 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/10 15:37:26 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_generic		fill_square(t_string *props)
{
	t_generic res;

	if (object_props_count(props) != 4)
		errcode(1);
	res.sq = (t_square *)malloc(sizeof(t_square));
	(res.sq)->point = fill_vec(props[0]);
	(res.sq)->normal = fill_vec(props[1]);
	(res.sq)->side = atod(props[2]);
	if ((res.sq)->side < 0)
	{
		free(res.sq);
		errcode(8);
	}
	if (!is_in_range(-1, res.sq->normal.x, 1) ||
		!is_in_range(-1, res.sq->normal.y, 1) ||
		!is_in_range(-1, res.sq->normal.z, 1))
	{
		free(res.sq);
		errcode(9);
	}
	(res.sq)->color = fill_rgb(props[3]);
	return (res);
}
