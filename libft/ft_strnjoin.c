/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:03:01 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/22 18:58:00 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(new = (char *)malloc(sizeof(*new) * (ft_strlen(s1) + n + 1))))
		return (NULL);
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] && i < n)
	{
		new[j] = s2[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}
