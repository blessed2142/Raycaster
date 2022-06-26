/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:13:58 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/01 22:24:46 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	list_n_killer(t_list **head)
{
	t_list	*tmp;
	t_list	*pred;
	char	*str;

	tmp = *head;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			str = ft_strdup(tmp->content);
			if (str[0] == '\0')
				pred->next = NULL;
			if (list_n_killer_help(str))
				break ;
			ft_lstclear(&tmp, &free);
			tmp = *head;
		}
		else
		{
			pred = tmp;
			tmp = tmp->next;
		}
	}
}

void	list_cleaner(t_list **head)
{
	t_list *tmp;
	t_list *pred;

	tmp = *head;
	pred = NULL;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			pred->next = NULL;
			ft_lstclear(&tmp, &free);
		}
		else
		{
			pred = tmp;
			tmp = tmp->next;
		}
	}
}

int		checklist(t_game *game, char *str)
{
	int i;

	i = 0;
	i = space_through(str, i);
	if (str[i] != '\0' && str[i] != '\n')
	{
		if (game->map_flag_n)
			error(4);
		game->map_flag = 1;
	}
	if (str[i] == '\0' || str[0] == '\0')
	{
		if (game->map_flag && str[0] == '\0')
		{
			game->map_flag = 0;
			game->map_flag_n = 1;
			return (1);
		}
		if (game->map_flag && str[0] != '\0')
			return (1);
		free(str);
		return (0);
	}
	return (1);
}

char	*list_to_str(const char *str, int max_len)
{
	int		str_len;
	int		diff;
	char	*ret;

	str_len = 0;
	diff = 0;
	if (!str)
		return (NULL);
	str_len = ft_strlen_g(str);
	if (str_len == max_len)
	{
		ret = ft_strdup(str);
		return (ret);
	}
	else
	{
		ret = cub_strjoin(ft_strdup(str), space_str(max_len - str_len));
		return (ret);
	}
}

void	list_free(t_list **head, int lst_size)
{
	int i;

	i = 0;
	while (i++ < lst_size - 1)
		list_cleaner(head);
	ft_lstclear(head, &free);
}
