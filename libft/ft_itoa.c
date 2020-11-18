/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:13:28 by anel-bou          #+#    #+#             */
/*   Updated: 2019/06/30 22:29:19 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*new;
	int				len;
	int				sign;
	unsigned int	nn;

	len = ft_decilen(n);
	if (!(new = (char *)malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	sign = (n < 0 ? -1 : 1);
	if (n == 0)
		new[0] = '0';
	nn = (n < 0 ? -n : n);
	new[len--] = '\0';
	while (nn > 0)
	{
		new[len] = nn % 10 + '0';
		nn /= 10;
		len--;
	}
	if (sign == -1)
		new[0] = '-';
	return (new);
}
