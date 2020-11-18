/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:03:01 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/24 22:03:29 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		tt;

	if (!s2 || !s1)
		return (NULL);
	tt = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2 || !(new = (char *)malloc(sizeof(*new) * (tt + 1))))
		return (NULL);
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	*new = '\0';
	return (new - tt);
}
