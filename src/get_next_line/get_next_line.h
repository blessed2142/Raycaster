/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 11:44:01 by rphoebe           #+#    #+#             */
/*   Updated: 2021/04/27 17:54:29 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*till_n(char *src);
char	*n_till(char *src);
int		ft_strlen_g(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif
