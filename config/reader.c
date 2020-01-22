/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:44:44 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/14 14:47:32 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

t_object		*reader(t_string scene)
{
	int				fd;
	int				res;
	t_string		line;
	static t_object	*head;

	fd = open(scene, O_RDONLY);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		line_parser(line, &head);
		ft_free((void **)&line);
	}
	line_parser(line, &head);
	ft_free((void **)&line);
	if (res == -1)
		errcode(3);
	return (head);
}
