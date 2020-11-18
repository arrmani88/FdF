/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:04:31 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/04 20:18:41 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s || !(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new = ft_strncpy(new, (const char *)s + start, len);
	new[len] = '\0';
	return (new);
}
