/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:44:31 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:59:02 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void		helper(t_lights *lst, t_object *head)
{
	lst->next = (t_lights *)malloc(sizeof(t_lights));
	lst = lst->next;
	lst->content = head->content.light;
	lst->next = NULL;
}

t_lights		*get_light_list(t_object *head)
{
	t_lights	*light_head;
	t_lights	*lst;

	light_head = NULL;
	while (head)
	{
		if (equals(head->type, "l"))
		{
			if (!light_head)
			{
				light_head = (t_lights *)malloc(sizeof(t_lights));
				light_head->content = head->content.light;
				light_head->next = NULL;
				lst = light_head;
			}
			else
				helper(lst, head);
		}
		head = head->next;
	}
	return (light_head);
}
