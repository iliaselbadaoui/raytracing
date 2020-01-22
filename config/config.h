/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:47:29 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/07 13:19:50 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# define BUFFER_SIZE 100
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../types.h"
# include "../utils/utils.h"
# include "../libft/libft.h"

void			fill_line(char **line, char *buffer);
int				process_line(char **line, char **remain);
int				process_remain(char **remain, char **line);
void			fill_list(t_object **head, t_string *components);
int				get_next_line(int fd, char **line);
t_object		*reader(t_string scene);
void			line_parser(t_string line, t_object **obj);
#endif
