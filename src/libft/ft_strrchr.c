/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:55:22 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/19 17:39:03 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*ss;

	i = ft_strlen(s) - 1;
	ss = (char *)s;
	j = 0;
	if ((char)c == '\0')
	{
		return (ss + i + 1);
	}
	while (j < i + 1)
	{
		if (ss[i] == (char)c)
		{
			return (ss + i);
			break ;
		}
		i--;
	}
	return (NULL);
}
