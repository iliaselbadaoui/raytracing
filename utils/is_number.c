/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:28:58 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/10 15:37:42 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			is_number(t_string input)
{
	int		res;

	res = 1;
	if (*input == '-')
	{
		input++;
		res += 3;
	}
	while ((*input))
	{
		if (((*input) < '0' || (*input) > '9') && (*input) != '.')
			return (0);
		if ((*input) == '.')
			res += 2;
		input++;
	}
	if (*(input - 1) == '.')
		res = 0;
	return (res);
}
