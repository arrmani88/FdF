/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 04:07:18 by anel-bou          #+#    #+#             */
/*   Updated: 2019/04/01 04:11:00 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int n;

	if (nb < 0)
		ft_putchar_fd('-', fd);
	n = (nb < 0 ? -nb : nb);
	if (n <= 9)
		ft_putchar_fd((n + '0'), fd);
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
}
