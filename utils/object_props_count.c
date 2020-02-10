/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_props_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:50:09 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/10 15:40:31 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		object_props_count(t_string *props)
{
	int	count;

	count = 0;
	while (props[count])
		count++;
	return (count);
}
