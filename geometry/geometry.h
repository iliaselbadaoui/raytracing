/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:32:48 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/17 19:46:04 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "../types.h"
# include "../utils/utils.h"
# include <stdlib.h>
# include <stdio.h>

int				spher_intersect(t_spher sp, t_ray ray, double *t);
t_vec			get_sphers_normal(t_spher s, t_vec pi);
t_vec			vec_diff(t_vec v1, t_vec v2);
t_vec			vec_add(t_vec v1, t_vec v2);
t_vec			vec_times_double(t_vec v, double d);
t_vec			vec_devided_double(t_vec v, double d);
t_vec			normalize_vect(t_vec vec);
double			vec_dot(t_vec v1, t_vec v2);
t_vec			vec_cross(t_vec v1, t_vec v2);
t_vec			vec_init(double x, double y, double z);
t_ray			ray_init(t_vec org, t_vec dir);
int				rgb_to_int(t_rgb rgb);
double			clamp_rgb(double min, double rgb_shadow, double max);
t_rgb			add_rgb(t_rgb c1, t_rgb c2);
t_rgb			rgb(unsigned short r, unsigned short g, unsigned short b);
double			min(double n1, double n2);
t_rgb			rgb_times_double(t_rgb rgb, double d);
t_result		check_intersections(t_object *lst, t_ray ray);
void			check_object(t_object lst, t_ray ray, double *solution, t_result *res);
double			vec_distance(t_vec v1, t_vec v2);
int				plane_intersect(t_plane plane, t_ray ray, double *t);
#endif
