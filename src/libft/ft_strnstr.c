/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:33:20 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/19 17:26:54 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	char_check(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (haystack[i] == needle[j])
	{
		i++;
		j++;
		if (needle[j] == '\0' && i <= len)
			return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
			c = char_check(haystack + i, needle + j, len - i);
		if (c == 1)
			return ((char *)haystack + i - j);
		if (c == 0)
			i++;
	}
	return (NULL);
}
