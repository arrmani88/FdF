/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:26:09 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/10 19:27:30 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(char *s, char c)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (s[++i])
			if (s[i] == c)
				count++;
	return (count);
}
