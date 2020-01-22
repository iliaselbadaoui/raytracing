/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:13:13 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/10 15:26:20 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_generic		fill_triangle(t_string *props)
{
	t_generic res;

	if (object_props_count(props) != 4)
		errcode(1);
	res.tr = (t_triangle *)malloc(sizeof(t_triangle));
	(res.tr)->p1 = fill_vec(props[0]);
	(res.tr)->p1 = fill_vec(props[1]);
	(res.tr)->p3 = fill_vec(props[2]);
	(res.tr)->color = fill_rgb(props[3]);
	return (res);
}
