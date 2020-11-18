/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 00:33:32 by anel-bou          #+#    #+#             */
/*   Updated: 2019/05/13 09:20:10 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstock(char *dst, char *src1, char *src2)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strjoin(src1, src2);
	while (*tmp)
		dst[i++] = *tmp++;
	dst[i] = '\0';
	free(tmp);
	return (dst);
}
