/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:08:33 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:16:39 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void	fill_arr(t_string *arr)
{
	arr[0] = "R";
	arr[1] = "A";
	arr[2] = "c";
	arr[3] = "l";
	arr[4] = "sq";
	arr[5] = "sp";
	arr[6] = "pl";
	arr[7] = "tr";
	arr[8] = "cy";
	arr[9] = "#";
	arr[10] = NULL;
}

int			match_type(t_string type)
{
	t_string	arr[11];
	int			i;

	fill_arr(arr);
	i = 0;
	while (arr[i])
	{
		if (equals(type, arr[i]))
			return (1);
		i++;
	}
	return (0);
}

void		line_parser(t_string line, t_object **obj)
{
	t_string		*components;
	t_string		*tmp;

	components = ft_split(line, ' ');
	if (object_props_count(components) == 0)
	{
		free_2d(&components);
		return ;
	}
	tmp = components;
	if (!match_type(*components))
	{
		free_2d(&components);
		errcode(0);
	}
	else
		fill_list(obj, tmp);
	free_2d(&components);
}
