/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:13:31 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/08 11:13:01 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_object	*create_object_node(t_string type, t_generic content)
{
	t_object	*node;

	node = (t_object *)malloc(sizeof(t_object));
	node->type = type;
	node->content = content;
	node->next = NULL;
	return (node);
}
