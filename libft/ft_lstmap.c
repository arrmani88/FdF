/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:22:57 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/09 16:19:32 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	tmp = new;
	while (lst->next)
	{
		tmp->next = f(lst->next);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (new);
}
