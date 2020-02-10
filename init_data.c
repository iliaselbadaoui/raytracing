/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:58:37 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/10 16:10:51 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_resolution	get_resolution(t_object *head)
{
	t_resolution	res;
	t_object		*nav;

	nav = head;
	while (!equals(nav->type, "R"))
		nav = nav->next;
	res = *(nav->content.res);
	if (res.height > 1620)
		res.height = 1620;
	if (res.width > 2880)
		res.width = 2880;
	return (res);
}

static t_ambient	get_ambient(t_object *head)
{
	t_ambient		amb;
	t_object		*nav;

	nav = head;
	while (!equals(nav->type, "A"))
		nav = nav->next;
	amb = *(nav->content.amb);
	return (amb);
}

void				init_data(t_object *head, char *argv)
{
	g_data.mlx.mlx = mlx_init();
	g_data.res = get_resolution(head);
	g_data.amb = get_ambient(head);
	get_first_cam(head);
	g_data.mlx.img = mlx_new_image(g_data.mlx.mlx, g_data.res.width,
	g_data.res.height);
	if (!argv)
		g_data.mlx.win = mlx_new_window(g_data.mlx.mlx, g_data.res.width,
		g_data.res.height, "MiniRT");
}
