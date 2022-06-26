/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:16:40 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/14 15:23:42 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dd;
	size_t	i;
	size_t	j;
	size_t	s;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_strlen(s1);
	if (!(dd = (char *)malloc(sizeof(char) * (s + ft_strlen(s2) + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		dd[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		dd[i] = s2[j];
		i++;
		j++;
	}
	dd[i] = '\0';
	return (dd);
}
