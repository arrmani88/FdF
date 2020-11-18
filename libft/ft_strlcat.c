/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:17:40 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/09 11:30:12 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	if (ldst >= size)
		return (lsrc + size);
	while (src[i] && (ldst + i + 1) < size)
	{
		dst[i + ldst] = src[i];
		i++;
	}
	dst[i + ldst] = '\0';
	return (lsrc + ldst);
}
