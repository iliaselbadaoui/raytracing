/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:22:01 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/10 16:11:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <mlx.h>
# include "libft/libft.h"
# include "geometry/geometry.h"
# include "config/config.h"
# include "types.h"

void			raytracer(t_object *head);
int				escape(int key);
int				check_args(int argc, t_string *args);
int				close_win(int key);
void			manage_window(t_mlx mlx);
void			put_pixel(int x, int y, int color);
void			init_data(t_object	*head, char *argv);
int				save_to_bitmap();
int				rotate_camera(int key);
#endif
