/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphers_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:00:12 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:28:24 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_vec	get_sphers_normal(t_spher s, t_vec pi)
{
	t_vec	res;

	res = vec_diff(s.center, pi);
	return (res);
}
