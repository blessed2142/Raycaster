/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:51:48 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/17 16:23:33 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_much_digs(int n)
{
	long int	nn;
	int			i;

	nn = n;
	if (n < 0)
	{
		i = 2;
		nn = -nn;
	}
	else
		i = 1;
	while (nn > 9)
	{
		nn = nn / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int			h;
	int			i;
	char		*s;
	long int	nn;

	h = how_much_digs(n);
	i = 0;
	nn = n;
	if (!(s = malloc(sizeof(char) * (h + 1))))
		return (NULL);
	if (nn < 0)
	{
		s[0] = '-';
		i++;
		nn = -nn;
	}
	s[h] = '\0';
	while (h > i)
	{
		h--;
		s[h] = nn % 10 + 48;
		nn = nn / 10;
	}
	return (s);
}
