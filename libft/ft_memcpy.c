/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:29:22 by bmbarga           #+#    #+#             */
/*   Updated: 2013/11/28 20:58:26 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;
	size_t	i;

	i = 0;
	if (!src || !dest)
		return (dest);
	tmp_s = (char*)src;
	tmp_d = (char*)dest;
	while (i < n)
	{
		*tmp_d = *tmp_s;
		tmp_s++;
		tmp_d++;
		i++;
	}
	return (dest);
}
