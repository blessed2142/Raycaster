/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:07:32 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/14 13:17:53 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ss;
	unsigned int	j;

	if (!s)
		return (NULL);
	j = 0;
	if (!(ss = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[j] != '\0')
	{
		ss[j] = (*f)(j, s[j]);
		j++;
	}
	ss[j] = '\0';
	return (ss);
}
