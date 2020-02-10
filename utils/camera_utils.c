/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:18:15 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:50:22 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		get_first_cam(t_object *head)
{
	t_object		*nav;

	nav = head;
	while (!equals(nav->type, "c") && nav)
		nav = nav->next;
	if (nav)
		g_data.cam = nav->content.cam;
}

void		get_last_cam(t_object *head)
{
	t_object		*nav;

	nav = head;
	while (nav)
	{
		if (equals(nav->type, "c") && nav)
			g_data.cam = nav->content.cam;
		nav = nav->next;
	}
}

void		get_next_cam(t_object *head)
{
	t_object		*nav;

	nav = head;
	if (!nav)
		return ;
	while (nav->content.cam != g_data.cam && nav)
		nav = nav->next;
	if (nav)
	{
		nav = nav->next;
		while (!equals(nav->type, "c") && nav->content.cam != g_data.cam)
		{
			nav = nav->next;
			if (!nav)
				break ;
		}
		if (nav)
			g_data.cam = nav->content.cam;
		else
			get_first_cam(g_object);
	}
}

void		get_prev_cam(t_object *head)
{
	t_object		*nav;

	nav = head;
	while (nav->content.cam != g_data.cam && nav)
	{
		if (equals(nav->type, "c"))
		{
			g_data.cam = nav->content.cam;
			break ;
		}
		nav = nav->next;
	}
	if (!nav)
		get_last_cam(g_object);
}
