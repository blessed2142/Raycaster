/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphoebe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 04:31:26 by rphoebe           #+#    #+#             */
/*   Updated: 2021/05/04 04:31:27 by rphoebe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;
	int		flag;

	flag = 1;
	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!(new_element = (ft_lstnew(f(lst->content)))))
		{
			ft_lstclear(&new_list, del);
			ft_lstclear(&lst, del);
			break ;
		}
		if (flag)
		{
			new_list = new_element;
			flag = 0;
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, new_element);
	}
	return (new_list);
}
