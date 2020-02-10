/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:54:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/09 21:42:57 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static	void	check4(t_object lst, t_ray ray, double *solution, t_result *res)
{
	if (equals(lst.type, "cy"))
	{
		res->flag = cylinder_intersect(*(lst.content.cy), ray, solution);
		res->color = (*(lst.content.cy)).color;
		res->sol = *solution;
		if (res->flag)
		{
			res->type = "cy";
			res->pi = vec_add(ray.org, vec_times_double(ray.dir, *solution));
			res->normal = normalize_vect(vec_diff(lst.content.cy->point,
			res->pi));
		}
	}
}

static	void	check3(t_object lst, t_ray ray, double *solution, t_result *res)
{
	if (equals(lst.type, "sq"))
	{
		res->flag = square_intersect(*(lst.content.sq), ray, solution);
		res->color = (*(lst.content.sq)).color;
		res->sol = *solution;
		if (res->flag)
		{
			res->type = "sq";
			res->pi = vec_add(ray.org, vec_times_double(ray.dir, *solution));
			res->normal = vec_cross(vec_diff(lst.content.sq->p2,
			lst.content.sq->p1), vec_diff(lst.content.sq->p3,
			lst.content.sq->p1));
		}
	}
	check4(lst, ray, solution, res);
}

static	void	check2(t_object lst, t_ray ray, double *solution, t_result *res)
{
	if (equals(lst.type, "tr"))
	{
		res->flag = tirangle_intersect(*(lst.content.tr), ray, solution);
		res->color = lst.content.tr->color;
		res->sol = *solution;
		if (res->flag)
		{
			res->type = "tr";
			res->pi = vec_add(ray.org, vec_times_double(ray.dir, *solution));
			res->normal = vec_cross(vec_diff(lst.content.tr->p2,
			lst.content.tr->p1), vec_diff(lst.content.tr->p3,
			lst.content.tr->p1));
		}
	}
	check3(lst, ray, solution, res);
}

static	void	check1(t_object lst, t_ray ray, double *solution, t_result *res)
{
	if (equals(lst.type, "pl"))
	{
		res->flag = plane_intersect(*(lst.content.plane), ray, solution);
		res->color = (*(lst.content.plane)).color;
		res->sol = *solution;
		if (res->flag)
		{
			res->type = "pl";
			res->pi = vec_add(ray.org, vec_times_double(ray.dir, *solution));
			res->normal = (*(lst.content.plane)).normal;
		}
	}
	check2(lst, ray, solution, res);
}

void			check_object(t_object lst, t_ray ray, double *solution,
	t_result *res)
{
	double		t;

	t = INFINITY;
	res->dir = ray.dir;
	if (equals(lst.type, "sp"))
	{
		res->flag = spher_intersect(*(lst.content.sp), ray, solution);
		res->color = lst.content.sp->color;
		res->sol = *solution;
		if (res->flag)
		{
			res->type = "sp";
			res->pi = vec_add(ray.org, vec_times_double(ray.dir, *solution));
			res->normal = normalize_vect(get_sphers_normal(*(lst.content.sp),
			res->pi));
		}
	}
	check1(lst, ray, solution, res);
}
