/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_in_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 10:02:21 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/19 10:09:36 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			vec_in_range(double min, t_vec vec, double max)
{
	if (!is_in_range(min, vec.x, max) || !is_in_range(min, vec.y, max) ||
		!is_in_range(min, vec.z, max))
		return (0);
	return (1);
}
