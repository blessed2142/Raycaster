/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 11:43:37 by rphoebe           #+#    #+#             */
/*   Updated: 2021/04/27 17:56:12 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../cub.h"

int		badr_hari(char **line, char **ne_line, char **buf)
{
	free(*buf);
	*line = till_n(*ne_line);
	*ne_line = n_till(*ne_line);
	return (1);
}

char	*join(char *s1, char *s2)
{
	char	*dd;
	int		i;
	int		j;
	int		sl1;
	int		sl2;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	sl1 = ft_strlen_g(s1);
	sl2 = ft_strlen_g(s2);
	if (!(dd = (char *)malloc(sizeof(char) * (sl1 + sl2 + 1))))
		return (NULL);
	while (i < sl1)
	{
		dd[i] = s1[i];
		i++;
	}
	while (j < sl2)
		dd[i++] = s2[j++];
	dd[i] = '\0';
	free(s1);
	return (dd);
}

int		gnl_help(char **line)
{
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*tmp;
	char		*buf;

	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1 || \
	line == NULL || !(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	{
		error(7);
		return (-1);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) || ft_strchr(tmp, '\n'))
	{
		buf[ret] = '\0';
		tmp = join(tmp, buf);
		if (ft_strchr(tmp, '\n') != NULL)
			return (badr_hari(line, &tmp, &buf));
	}
	free(buf);
	if (!tmp)
		return (gnl_help(line));
	*line = tmp;
	tmp = NULL;
	return (0);
}
