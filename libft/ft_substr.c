/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:58:01 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/07 21:42:22 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!s || (int)start > ft_strlen(s))
		return (NULL);
	if (!(res = (char *)malloc(len + 1)))
	{
		free(res);
		return (NULL);
	}
	s += start;
	i = 0;
	while (i < len)
	{
		res[i] = *s;
		i++;
		s++;
	}
	res[i] = '\0';
	return (res);
}
