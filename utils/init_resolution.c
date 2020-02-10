/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:15:42 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:58:30 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_resolution	init_resolution(int width, int height)
{
	t_resolution	res;

	res.width = width;
	res.height = height;
	return (res);
}

t_img_point		init_imgpoint(int x, int y)
{
	t_img_point	res;

	res.x = x;
	res.y = y;
	return (res);
}
