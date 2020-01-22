/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:48:41 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/13 23:00:59 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_args(int argc, t_string *args)
{
	t_string	*fn;

	fn = ft_split(args[1], '.');
	if (!equals(fn[object_props_count(fn) - 1], "rt"))
	{
		free_2d(&fn);
		return (0);
	}
	else if (argc == 3)
		if (!equals(args[2], "--save"))
		{
			free_2d(&fn);
			return (0);
		}
	return (1);
}
