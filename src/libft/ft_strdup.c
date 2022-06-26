/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:23:53 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/14 15:26:08 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ss1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	if (!(ss1 = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s1[j] != '\0')
	{
		ss1[j] = s1[j];
		j++;
	}
	ss1[j] = '\0';
	return (ss1);
}
