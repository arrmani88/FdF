/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:21:32 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/16 09:34:45 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_fo
{
	char f1;
	char f2;
	char f3;
	char f4;
	char co;
	char bk;
}				t_fo;

int				gv(char a)
{
	if ((a == 'r') || (a == 'g') || (a == 'y') || (a == 'b') || (a == 'm') ||
	(a == 'c') || (a == 'w') || (a == 'k'))
		return (1);
	if ((a == 'u') || (a == 't') || (a == 'i') || (a == 'f') || (a == 'n'))
		return (2);
	if ((a == 'R') || (a == 'G') || (a == 'Y') || (a == 'B') || (a == 'M') ||
	(a == 'C') || (a == 'K') || (a == 'W'))
		return (3);
	return (0);
}

int				get_col(char v, char *s, int i, int maj)
{
	int c;

	c = 0;
	if (v)
	{
		s[i++] = ((!maj) ? '3' : '4');
		((!s[i] && v == 'k' - maj && (s[i] = '0')) ||
		(!s[i] && v == 'r' - maj && (s[i] = '1')) ||
		(!s[i] && v == 'g' - maj && (s[i] = '2')) ||
		(!s[i] && v == 'y' - maj && (s[i] = '3')) ||
		(!s[i] && v == 'b' - maj && (s[i] = '4')) ||
		(!s[i] && v == 'm' - maj && (s[i] = '5')) ||
		(!s[i] && v == 'c' - maj && (s[i] = '6')) ||
		(!s[i] && v == 'w' - maj && (s[i] = '7')));
		i++;
		s[i++] = ';';
	}
	return (i);
}

int				get_fon(char fo, char *s, int i)
{
	if (fo)
	{
		((!s[i] && fo == 'u' && (s[i] = '4')) ||
		(!s[i] && fo == 't' && (s[i] = '2')) ||
		(!s[i] && fo == 'f' && (s[i] = '1')) ||
		(!s[i] && fo == 'n' && (s[i] = '0')) ||
		(!s[i] && fo == 'i' && (s[i] = '3')));
		i++;
		s[i++] = ';';
	}
	return (i);
}

int				ft_putcol(t_fo f)
{
	char	*s;
	int		c;
	int		i;

	if (!f.co && !f.f1 && !f.bk && (write(1, "\033[0m", 4)))
		return (1);
	i = 0;
	c = 0;
	s = ft_strnew(16);
	s[i++] = '\033';
	s[i++] = '[';
	i = get_fon(f.f1, s, i);
	i = get_fon(f.f2, s, i);
	i = get_fon(f.f3, s, i);
	i = get_fon(f.f4, s, i);
	i = get_col(f.co, s, i, 0);
	i = get_col(f.bk, s, i, 32);
	s[--i] = 'm';
	if (*s && *s == '\033' && s[i] == 'm')
		ft_putstr(s);
	free(s);
	return (0);
}

int				manage_cols(char *s)
{
	char	*p;
	t_fo	f;

	if (s[1] == 'e' && (write(1, "\033[0m", 4)))
		return (1);
	ft_bzero(&f, sizeof(f));
	p = s;
	while (!f.co && *(++s) && *s != '}')
		f.co = ((gv(*s) == 1) ? *s : 0);
	s = p;
	while (!f.bk && *(++s) && *s != '}')
		f.bk = ((gv(*s) == 3) ? *s : 0);
	s = p;
	while (!f.f1 && *(s++) && *s != '}')
		f.f1 = ((gv(*s) == 2) ? *s : 0);
	s = p;
	while (!f.f2 && *(s++) && *s != '}')
		f.f2 = ((gv(*s) == 2) && *s != f.f1 ? *s : 0);
	s = p;
	while (!f.f3 && *(s++) && *s != '}')
		f.f3 = ((gv(*s) == 2) && *s != f.f1 && *s != f.f2 ? *s : 0);
	s = p;
	while (!f.f4 && *(s++) && *s != '}')
		f.f4 = (gv(*s) == 2 && *s != f.f1 && *s != f.f2 && *s != f.f3 ? *s : 0);
	return (ft_putcol(f));
}
