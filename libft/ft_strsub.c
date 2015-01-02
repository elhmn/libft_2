/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 04:30:55 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/02 20:47:16 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t size)
{
	char	*new_str;
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	new_str = NULL;
	if (s)
	{
		new_str = ft_strnew(size);
		if (!new_str)
			return (NULL);
		while (i < ft_strlen(s) && i < size && tmp && *tmp)
		{
			new_str[i] = tmp[start];
			i++;
			start++;
		}
	}
	return (new_str);
}
