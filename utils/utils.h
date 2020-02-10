/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:34:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/10 13:00:50 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../types.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

int				equals(t_string s1, t_string s2);
void			add_object_node(t_object **head, t_object *new);
t_object		*create_object_node(t_string type, t_generic content);
t_object		*get_before_last(t_object *head);
void			clear_object_list(t_object **head);
t_resolution	*create_resolution(int width, int height);
t_object		*create_resolution_object(t_string	*components);
double			double_abs(double d);
int				vec_in_range(double min, t_vec vec, double max);
double			deg_to_rad(int deg);
t_lights		*get_light_list(t_object *head);
int				match_type(t_string type);
void			ft_free(void **p);
t_resolution	init_resolution(int width, int height);
t_img_point		init_imgpoint(int x, int y);
t_generic		fill_resolution(t_string	*props);
t_generic		fill_ambient(t_string *props);
t_generic		fill_camera(t_string *props);
t_generic		fill_light(t_string *props);
t_generic		fill_plane(t_string *props);
t_generic		fill_sphere(t_string *props);
t_generic		fill_square(t_string *parts);
t_generic		fill_cylinder(t_string *props);
t_generic		fill_triangle(t_string *props);
t_rgb			fill_rgb(t_string rgb);
t_vec			fill_vec(t_string vec);
void			get_first_cam(t_object *head);
void			get_last_cam(t_object *head);
void			get_next_cam(t_object *head);
void			get_prev_cam(t_object *head);
t_vec			x_rotation(t_vec vec, double alpha);
t_vec			y_rotation(t_vec vec, double alpha);
t_vec			z_rotation(t_vec vec, double alpha);
void			errcode(int code);
int				object_props_count(t_string	*props);
int				is_number(t_string	input);
int				is_in_range(double min, double value, double max);
double			atod(t_string input);
t_rgb			int_to_rgb(int col);
double			floating_part(t_string after_point);
void			free_2d(t_string **arr);
#endif
