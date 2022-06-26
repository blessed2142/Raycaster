/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:36:04 by rphoebe           #+#    #+#             */
/*   Updated: 2021/04/20 21:46:34 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		left_trim(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		while (s2[j] != '\0')
		{
			while (s1[i] == s2[j])
			{
				i++;
				j = 0;
			}
			j++;
		}
		break ;
	}
	return (i);
}

static	int		right_trim(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int h;

	i = ft_strlen(s1) - 1;
	j = 0;
	h = 0;
	if (s1 == NULL)
		return (0);
	while (i > 0)
	{
		while (s2[j] != '\0')
		{
			while (s1[i] == s2[j] && i > 0)
			{
				h++;
				i--;
				j = 0;
			}
			j++;
		}
		break ;
	}
	return (h);
}

char			*full(const char *s, size_t len, size_t begin)
{
	size_t	i;
	char	*new;

	i = 0;
	if (len < 0)
		return (NULL);
	if (s == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		new[i] = s[begin];
		begin++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	size_t	left;
	size_t	right;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	len = 0;
	left = left_trim(s1, set);
	right = right_trim(s1, set);
	len = ft_strlen(s1) - left - right;
	if (len < 0)
		len = 0;
	str = full(s1, len, left);
	return (str);
}
