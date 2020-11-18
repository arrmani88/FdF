/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:44:40 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/10 13:13:24 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *cp;

	if (!(cp = (char *)malloc(sizeof(*cp) * (len + 1))))
		return (NULL);
	ft_memcpy(cp, src, len);
	ft_memcpy(dst, cp, len);
	free(cp);
	return (dst);
}
