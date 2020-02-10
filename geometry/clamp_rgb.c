/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:03:14 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:18:41 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double		clamp_rgb(double min, double rgb_shadow, double max)
{
	if (min <= rgb_shadow && rgb_shadow <= max)
		return (rgb_shadow);
	else if (rgb_shadow < min)
		return (min);
	else
		return (max);
}

double		min(double n1, double n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

double		max(double n1, double n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}
