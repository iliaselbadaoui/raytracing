/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:01:33 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/10 15:26:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_generic		fill_sphere(t_string *props)
{
	t_generic res;

	if (object_props_count(props) != 3)
		errcode(1);
	res.sp = (t_spher *)malloc(sizeof(t_spher));
	(res.sp)->center = fill_vec(props[0]);
	(res.sp)->diameter = atod(props[1]);
	if ((res.sp)->diameter < 0)
	{
		free(res.sp);
		errcode(8);
	}
	(res.sp)->color = fill_rgb(props[2]);
	return (res);
}
