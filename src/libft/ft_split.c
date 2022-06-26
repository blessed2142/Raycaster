/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:20:55 by rphoebe           #+#    #+#             */
/*   Updated: 2020/11/19 17:27:50 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		words(const char *s, char c)
{
	size_t i;
	size_t w;
	size_t d;

	i = 0;
	w = 0;
	d = ft_strlen(s) - 1;
	if (!s || s[0] == '\0')
		return (0);
	if (s[0] == c)
		i = 1;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i - 1] != c))
			w++;
		i++;
	}
	if (s[d] != c)
		w++;
	return (w);
}

static	size_t		dlina(const char *s, char c, int i)
{
	size_t	d;

	d = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		d++;
	}
	return (d);
}

static	char		*full(char *s, size_t len, size_t j)
{
	size_t	i;
	char	*s1;

	if (!s)
		return (NULL);
	if (!(s1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1[i] = s[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static	char		*mem_free(char **ss)
{
	while (*ss)
		free(*ss++);
	free(ss);
	return (NULL);
}

char				**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	d;
	char	**ss;

	i = 0;
	j = 0;
	d = 0;
	if (!s)
		return (NULL);
	if (!(ss = (char **)malloc(sizeof(char *) * (words(s, c) + 1))))
		return (NULL);
	while (j < (words(s, c)) && s[i] != '\0')
	{
		if (s[i] != c)
		{
			d = dlina((char *)s, c, i);
			if (!(ss[j++] = full((char *)s, d, i)))
				mem_free(ss);
			i = i + d;
		}
		i++;
	}
	ss[j] = NULL;
	return (ss);
}
