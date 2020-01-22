/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:50:01 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/14 14:45:05 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_generic		fill_ambient(t_string *props)
{
	t_generic	amb;

	if (object_props_count(props) != 2)
		errcode(1);
	amb.amb = (t_ambient *)malloc(sizeof(t_ambient));
	if (is_number(*props))
	{
		amb.amb->range = atod(*props);
		if (amb.amb->range < 0 || amb.amb->range > 1)
		{
			ft_free((void **)&(amb.amb));
			errcode(4);
		}
	}
	else
	{
		errcode(2);
		ft_free((void **)&(amb.amb));
	}
	amb.amb->color = fill_rgb(*(props + 1));
	return (amb);
}
