/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 18:45:34 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/10 15:19:30 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_resolution	*create_resolution(int width, int height)
{
	t_resolution	*resolution;

	resolution = (t_resolution *)malloc(sizeof(t_resolution));
	resolution->width = width;
	resolution->height = height;
	return (resolution);
}
