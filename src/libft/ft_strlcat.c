/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:22:44 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/17 14:36:54 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			dl;
	size_t			sl;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dstsize != 0 && dl < dstsize)
	{
		while (i < dstsize - dl - 1 && s[i] != '\0')
		{
			d[dl + i] = s[i];
			i++;
		}
		d[dl + i] = '\0';
		return (dl + sl);
	}
	return (dstsize + sl);
}
