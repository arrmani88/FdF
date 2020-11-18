/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:17:49 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/07 18:58:58 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **mai, void (*del)(void*, size_t))
{
	if (mai)
	{
		del((*mai)->content, (*mai)->content_size);
		free(*mai);
		*mai = NULL;
	}
}
