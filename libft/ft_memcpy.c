/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 09:23:20 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/02 21:31:28 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t m;

	m = n;
	while (n)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src++;
		n--;
	}
	return (dst - m);
}
