/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 15:51:58 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/03 11:34:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	const char	*tmp;
	int			nbr;
	int			sign;

	sign = 1;
	tmp = str;
	while ((*tmp == '\n' || *tmp == '\v' || *tmp == '\t')
			|| (*tmp == '\f' || *tmp == ' ' || *tmp == '\r' || *tmp == '\033' || *tmp == '+'))
		tmp++;
	if (*tmp == '-')
	{
		sign = 0;
		tmp++;
	}
	nbr = 0;
	while (*tmp && ft_isdigit(*tmp))
	{
		nbr = nbr * 10 + (*tmp - '0');
		tmp++;
	}
	if (!sign)
		return (nbr * -1);
	return (nbr);
}
