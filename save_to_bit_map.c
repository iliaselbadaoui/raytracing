/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_to_bit_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:16:13 by ielbadao          #+#    #+#             */
/*   Updated: 2020/02/10 17:02:28 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bmp_header		get_img_data(void)
{
	t_bmp_header	header;

	header.width = g_data.res.width;
	header.height = g_data.res.height;
	header.bitcount = 24;
	header.width_in_bytes = ((header.width * header.bitcount + 31) / 32) * 4;
	header.imagesize = header.width_in_bytes * header.height;
	header.bisize = 40;
	header.bfoffbits = 54;
	header.filesize = 54 + header.imagesize;
	header.biplanes = 1;
	return (header);
}

static unsigned char	*get_header(void)
{
	unsigned char	*header;
	t_bmp_header	data;

	header = (unsigned char *)ft_calloc(54, sizeof(header));
	data = get_img_data();
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &data.filesize, 4);
	ft_memcpy(header + 10, &data.bfoffbits, 4);
	ft_memcpy(header + 14, &data.bisize, 4);
	ft_memcpy(header + 18, &data.width, 4);
	ft_memcpy(header + 22, &data.height, 4);
	ft_memcpy(header + 26, &data.biplanes, 2);
	ft_memcpy(header + 28, &data.bitcount, 2);
	ft_memcpy(header + 34, &data.imagesize, 4);
	return (header);
}

static void				create_bmp(unsigned char *buf)
{
	int				output;
	t_bmp_header	data;

	data = get_img_data();
	output = open("./image.bmp", O_WRONLY | O_APPEND | O_CREAT, 777);
	write(output, get_header(), 54);
	write(output, (char *)buf, data.imagesize);
	close(output);
	free(buf);
}

static void				fill_image(unsigned char *buf, int *data,
	int col, int row)
{
	t_rgb	rgb;
	int		color_int;

	color_int = data[(g_data.res.width - row) * g_data.res.height + col];
	rgb = int_to_rgb(color_int);
	buf[row * get_img_data().width_in_bytes + col * 3 + 0] = rgb.b;
	buf[row * get_img_data().width_in_bytes + col * 3 + 1] = rgb.g;
	buf[row * get_img_data().width_in_bytes + col * 3 + 2] = rgb.r;
}

int						save_to_bitmap(void)
{
	int				col;
	int				row;
	unsigned char	*buf;
	unsigned char	*header;
	int				*data;

	header = get_header();
	buf = malloc(get_img_data().imagesize);
	data = (int *)mlx_get_data_addr(g_data.mlx.img, &col, &col, &col);
	row = g_data.res.height - 1;
	while (row >= 0)
	{
		col = 0;
		while (col < g_data.res.width)
		{
			fill_image(buf, data, col, row);
			col++;
		}
		row--;
	}
	create_bmp(buf);
	return (1);
}
