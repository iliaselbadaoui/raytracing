/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:01:04 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/29 21:13:58 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int		rgb_to_int(t_rgb rgb)
{
	return ((rgb.r * 256 * 256) + (rgb.g * 256) + rgb.b);
}

t_rgb	rgb(unsigned short r, unsigned short g, unsigned short b)
{
	return ((t_rgb){r, g, b});
}

t_rgb	rgb_times_double(t_rgb rgb, double d)
{
	d = clamp_rgb(0, d, 255);
	rgb.r *= d;
	rgb.g *= d;
	rgb.b *= d;
	return (rgb);
}

t_rgb	add_rgb(t_rgb c1, t_rgb c2)
{
	return ((t_rgb){clamp_rgb(0, c1.r + c2.r, 255),
			clamp_rgb(0, c1.g + c2.g, 255),
			clamp_rgb(0, c1.b + c2.b, 255)});
}
