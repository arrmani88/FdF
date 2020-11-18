/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_nb_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:48:17 by anel-bou          #+#    #+#             */
/*   Updated: 2019/05/13 09:21:13 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_nb_chr(t_list **alst, size_t nb)
{
	while ((*alst) != NULL)
	{
		if ((*alst)->content_size == nb)
			return (*alst);
		else
			*alst = (*alst)->next;
	}
	return (0);
}
