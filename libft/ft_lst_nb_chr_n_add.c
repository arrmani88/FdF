/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_nb_chr_n_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:16:28 by anel-bou          #+#    #+#             */
/*   Updated: 2019/05/13 09:23:34 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_nb_chr_n_add(t_list **alst, int fd)
{
	t_list *new;

	new = *alst;
	if ((ft_lst_nb_chr(&new, fd)) == 0)
		ft_lstadd(alst, ft_lstnew("\0", fd));
	new = *alst;
	return (ft_lst_nb_chr(&new, fd));
}
