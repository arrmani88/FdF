/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 08:58:26 by anel-bou          #+#    #+#             */
/*   Updated: 2019/03/30 13:40:58 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *bb;

	bb = (unsigned char *)b;
	while (n)
	{
		*bb = (unsigned char)c;
		bb++;
		n--;
	}
	return (b);
}
