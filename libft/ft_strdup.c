/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:34:05 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/04 13:47:22 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*n;
	int		i;

	if (!(n = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	if (n == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		n[i] = s[i];
		i++;
	}
	n[i] = 0;
	return (n);
}
