/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_before_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:16:28 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/10 15:37:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_object	*get_before_last(t_object *head)
{
	t_object	*tmp;

	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}
