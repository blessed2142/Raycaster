/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:18:04 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/14 15:27:29 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	if ((char)c == '\0')
	{
		while (s[i] != '\0')
		{
			i++;
		}
		return (ss + i);
	}
	else
	{
		while (*s)
		{
			if (*s++ == (char)c)
				return (ss + i);
			i++;
		}
	}
	return (NULL);
}
