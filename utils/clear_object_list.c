/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_object_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 01:12:07 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/15 20:33:23 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	free_content(t_string type, t_generic content)
{
	if (equals(type, "R"))
		ft_free((void **)content.res);
	else if (equals(type, "A"))
		free(content.amb);
	else if (equals(type, "c"))
		free(content.cam);
	else if (equals(type, "l"))
		free(content.light);
	else if (equals(type, "pl"))
		free(content.plane);
	else if (equals(type, "sp"))
		free(content.sp);
	else if (equals(type, "sq"))
		free(content.sq);
	else if (equals(type, "cy"))
		free(content.cy);
	else if (equals(type, "tr"))
		free(content.tr);
}

void		clear_object_list(t_object **head)
{
	t_object	*tmp;

	tmp = *head;
	while (tmp)
	{
		*head = (*head)->next;
		free_content(tmp->type, tmp->content);
		free(tmp);
		tmp = *head;
	}
}
