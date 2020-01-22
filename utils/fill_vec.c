/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:24:36 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/09 12:11:01 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec	fill_vec(t_string vec)
{
	t_vec		res;
	t_string	*parts;

	parts = ft_split(vec, ',');
	if (object_props_count(parts) != 3)
	{
		free_2d(&parts);
		errcode(1);
	}
	if (is_number(parts[0]) && is_number(parts[1]) && is_number(parts[2]))
	{
		res.x = atod(*(parts));
		res.y = atod(*(parts + 1));
		res.z = atod(*(parts + 2));
	}
	else
	{
		free_2d(&parts);
		errcode(2);
	}
	free_2d(&parts);
	return (res);
}
