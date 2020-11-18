/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:03:30 by anel-bou          #+#    #+#             */
/*   Updated: 2019/07/23 10:48:21 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*r;
	int		i;

	if (!s || !(r = ft_stralloc((char *)s, ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		r[i] = f(s[i]);
	r[i] = '\0';
	return (r);
}
