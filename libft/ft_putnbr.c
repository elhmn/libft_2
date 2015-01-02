/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 01:16:44 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/02 22:20:34 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void	ft_put_aux_nbr(int n)
{
	if (n >= 10)
	{
		ft_put_aux_nbr(n / 10);
		ft_put_aux_nbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void		ft_putnbr(int n)
{
	if (n == MIN_NBR)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_put_aux_nbr(n * -1);
	}
	else
		ft_put_aux_nbr(n);
}
