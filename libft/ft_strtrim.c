/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:04:40 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/13 14:27:35 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (i <= len && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	if (!(new = (char *)malloc(sizeof(*s) * (len + 1 - i + 1))))
		return (NULL);
	ft_strncpy(new, ((char *)s) + i, (len + 1 - i));
	new[len + 1 - i] = '\0';
	return (new);
}
