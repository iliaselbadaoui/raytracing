/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:13:41 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/20 14:38:41 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double		floating_part(t_string after_point)
{
	double	res;
	double	holder;
	int		times;
	int		start;

	res = 0;
	times = 0;
	while (*after_point)
	{
		start = 0;
		holder = *after_point - 48;
		while (start <= times)
		{
			holder /= 10;
			start++;
		}
		res += holder;
		times++;
		after_point++;
	}
	return (res);
}

double		atod(t_string input)
{
	double		res;
	double		sign;
	t_string	point;

	sign = 1;
	if (*input == '-')
	{
		input++;
		sign = -1;
	}
	res = (double)ft_atoi(input);
	if ((point = ft_strchr(input, '.')))
	{
		if (res >= 0)
			res += floating_part(ft_strchr(input, '.') + 1);
		else
			res -= floating_part(ft_strchr(input, '.') + 1);
	}
	return (res * sign);
}
