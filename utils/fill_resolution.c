/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:18:07 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/17 17:44:29 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_generic		fill_resolution(t_string *props)
{
	t_generic	res;

	if (object_props_count(props) != 2)
		errcode(1);
	res.res = (t_resolution *)malloc(sizeof(t_resolution));
	if (is_number(*props) == 1)
		(res.res)->width = ft_atoi(*props);
	else
	{
		ft_free((void **)&(res.res));
		errcode(2);
	}
	if (is_number(*(props + 1)) == 1)
		(res.res)->height = ft_atoi(*(props + 1));
	else
	{
		ft_free((void **)&(res.res));
		errcode(2);
	}
	return (res);
}
