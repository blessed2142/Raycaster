/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:17:31 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 01:17:33 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_list	*ft_lstnew_dope(void *content)
{
	t_list *result;

	if (!(result = malloc(sizeof(t_list))))
		return (NULL);
	result->content = ft_strdup((char *)content);
	result->next = NULL;
	return (result);
}

void	ft_lstadd_back_dope(t_list **lst, t_list *new, t_game *game, char *str)
{
	t_list *last;

	parser(game, str);
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->next = NULL;
}

int		max_len_content(t_list **head)
{
	int		max_len;
	int		contlen;
	t_list	*tmp;

	max_len = 0;
	contlen = 0;
	tmp = *head;
	while (tmp)
	{
		contlen = ft_strlen_g(tmp->content);
		max_len = contlen > max_len ? contlen : max_len;
		tmp = tmp->next;
	}
	return (max_len);
}

void	ft_lstclear_dope(t_list **lst, void (*del)(void *), char *str)
{
	t_list *tmp;

	free(str);
	tmp = *lst;
	(*del)(tmp->content);
	(*del)(tmp->next);
	free(tmp);
	*lst = NULL;
}

int		list_n_killer_help(char *str)
{
	int i;

	i = 0;
	if (str[0] != '\0')
		i = 1;
	free(str);
	return (i);
}
