/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 10:57:35 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/10 16:55:56 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# define SUCCESS	0
# define FAILURE	1

typedef char	*t_string;
typedef struct	s_resolution
{
	int		height;
	int		width;
}				t_resolution;
typedef struct	s_img_point
{
	double x;
	double y;
}				t_img_point;
typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_mlx;
typedef struct	s_equation
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	s0;
	double	s1;
}				t_equation;
typedef struct	s_rgb
{
	unsigned short	r;
	unsigned short	g;
	unsigned short	b;
}				t_rgb;
typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;
typedef struct	s_ray
{
	t_vec	org;
	t_vec	dir;
}				t_ray;
typedef struct	s_plane
{
	t_vec	point;
	t_vec	normal;
	t_rgb	color;
}				t_plane;
typedef struct	s_spher
{
	t_vec	center;
	t_rgb	color;
	double	diameter;
}				t_spher;
typedef struct	s_camera
{
	t_vec	pos;
	t_vec	normal;
	int		fov;
}				t_camera;
typedef struct	s_light
{
	t_vec	pos;
	float	range;
	t_rgb	color;
}				t_light;
typedef struct	s_lights
{
	t_light			*content;
	struct s_lights	*next;
}				t_lights;

typedef struct	s_ambient
{
	t_rgb	color;
	double	range;
}				t_ambient;
typedef struct	s_square
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
	t_vec	p4;
	t_rgb	color;
}				t_square;
typedef struct	s_cylinder
{
	t_vec	point;
	t_vec	normal;
	double	diameter;
	double	height;
	t_rgb	color;
}				t_cylinder;
typedef struct	s_triangle
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
	t_rgb	color;
}				t_triangle;
typedef struct	s_tirangle_solve
{
	t_vec	ab;
	t_vec	bc;
	t_vec	ca;
	t_vec	n;
	double	ndotraydirection;
	double	d;
	t_vec	point;
	t_vec	ap;
	t_vec	bp;
	t_vec	u;
	t_vec	v;
}				t_tirangle_solve;

typedef struct	s_result
{
	int			flag;
	double		sol;
	t_string	type;
	t_vec		pi;
	t_vec		point;
	t_vec		normal;
	t_rgb		color;
	t_vec		dir;
	void		*current;
}				t_result;
typedef struct	s_generic
{
	t_resolution	*res;
	t_ambient		*amb;
	t_camera		*cam;
	t_light			*light;
	t_spher			*sp;
	t_plane			*plane;
	t_square		*sq;
	t_cylinder		*cy;
	t_triangle		*tr;
}				t_generic;
typedef struct	s_object
{
	t_string		type;
	t_generic		content;
	struct s_object	*next;
}				t_object;
typedef struct	s_rotation
{
	double	ro;
	double	phi;
	double	teta;
}				t_rotation;
typedef struct	s_uvw
{
	t_vec	u;
	t_vec	v;
	t_vec	w;
	double	ph;
	double	pw;
}				t_uvw;
struct			s_flag
{
	int		resolution;
	int		ambient;
	int		camera;
}				g_flag;
struct			s_data
{
	t_mlx			mlx;
	t_resolution	res;
	t_ambient		amb;
	t_camera		*cam;
	t_lights		*lst;
}				g_data;
typedef struct	s_bmp_header
{
	int		width;
	int		height;
	int		bitcount;
	int		width_in_bytes;
	int		imagesize;
	int		bisize;
	int		bfoffbits;
	int		filesize;
	int		biplanes;
}				t_bmp_header;
t_object		*g_object;
#endif
