/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 12:42:09 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/05 10:55:20 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_string	g_errs[] = {"Error\nundefined type.",
	"Error\nthe number of object's properties is more or less than expected.",
	"Error\nproperty is not a number, or containing an error",
	"Error\nscene file not found.",
	"Error\nlighting ratio should be in the range [0.0 , 1.0].",
	"Error\nrgb color not int the rang [(0, 0, 0) , (255, 255, 255)].",
	"Error\nduplicated UNIQUE object",
	"Error\nthe field of view should be positive intger in the range [0, 180]",
	"Error\nall distances should be of positive values, you piece of shit",
	"Error\nthe normal vector coordinates should be in the range [-1, 1]",
	"Error\nnumber of args is less or more than expected",
	"Error\nfile is not rt scene file or mistake in arg name",
	"Error\nscene file should contain at least Resolution and Camera",
	"Error\npoints of square doesn't form a square"};

void		errcode(int code)
{
	perror(g_errs[code]);
	exit(FAILURE);
}
