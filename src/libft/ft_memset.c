/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:15:35 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/14 15:50:00 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*z;

	z = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		z[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
