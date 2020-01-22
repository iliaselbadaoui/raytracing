/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:46:23 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/10 15:23:53 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_generic		fill_light(t_string *props)
{
	t_generic res;

	if (object_props_count(props) != 3)
		errcode(1);
	res.light = (t_light *)malloc(sizeof(t_light));
	(res.light)->pos = fill_vec(props[0]);
	(res.light)->range = atod(props[1]);
	if (!is_in_range(0, (res.light)->range, 1))
	{
		free(res.light);
		errcode(4);
	}
	(res.light)->color = fill_rgb(props[2]);
	return (res);
}
