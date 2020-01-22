/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:38:35 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/14 14:42:26 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static	void	fill_list_helper(t_object **head, t_string *components)
{
	if (equals(*components, "pl"))
		add_object_node(head, create_object_node("pl",
		fill_plane(components + 1)));
	else if (equals(*components, "sp"))
		add_object_node(head, create_object_node("sp",
		fill_sphere(components + 1)));
	else if (equals(*components, "sq"))
		add_object_node(head, create_object_node("sq",
		fill_square(components + 1)));
	else if (equals(*components, "cy"))
		add_object_node(head, create_object_node("cy",
		fill_cylinder(components + 1)));
	else if (equals(*components, "tr"))
		add_object_node(head, create_object_node("tr",
		fill_triangle(components + 1)));
}

void			fill_list(t_object **head, t_string *components)
{
	if (equals(*components, "R") && !g_flag.resolution)
	{
		g_flag.resolution = 1;
		add_object_node(head, create_object_node("R",
		fill_resolution(components + 1)));
	}
	else if (equals(*components, "R") && g_flag.resolution)
		errcode(6);
	else if (equals(*components, "A") && !g_flag.ambient)
	{
		g_flag.ambient = 1;
		add_object_node(head, create_object_node("A",
		fill_ambient(components + 1)));
	}
	else if (equals(*components, "A") && g_flag.ambient)
		errcode(6);
	else if (equals(*components, "c"))
		add_object_node(head, create_object_node("c",
		fill_camera(components + 1)));
	else if (equals(*components, "l"))
		add_object_node(head, create_object_node("l",
		fill_light(components + 1)));
	else
		fill_list_helper(head, components);
}
