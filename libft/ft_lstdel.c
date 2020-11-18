/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:27:34 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/08 12:30:27 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **mai, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *lnxt;

	if (mai == NULL || *mai == NULL || del == NULL)
		return ;
	lst = *mai;
	while (lst != NULL)
	{
		lnxt = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lnxt;
	}
	*mai = NULL;
}
