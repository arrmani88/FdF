/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 11:46:37 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/04 20:44:01 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		index;
	char	**new;

	if (!s ||
	!(new = (char **)malloc(sizeof(char*) * (ft_cwordcount(s, c) + 1))))
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			new[index] = (char *)malloc(sizeof(*s) *
					(ft_clettercount(&s[i], c) + 1));
			ft_strncpy(new[index], &s[i], ft_clettercount(&s[i], c));
			new[index][ft_clettercount(&s[i], c)] = '\0';
			index++;
		}
		i++;
	}
	new[index] = 0;
	return (new);
}
