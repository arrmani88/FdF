/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 02:55:31 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/17 23:12:01 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ABS(X) ((X >= 0) ? X : -(X))
#define NDX (int)(v->line_sz * a.y + a.x)
#define COLOR 0xFFFF00

void			horizontal_oblique_segment(t_pt a, t_pt b, t_fv *v)
{
	t_segm_v s;

	s.dx = ABS(b.x - a.x);
	s.dy = ABS(b.y - a.y);
	s.xinc = (b.x > a.x) ? 1 : -1;
	s.yinc = (b.y > a.y) ? 1 : -1;
	(b.x == a.x) ? s.xinc = 0 : 0;
	(b.y == a.y) ? s.yinc = 0 : 0;
	s.initdx = s.dx;
	s.initdy = s.dy;
	s.stp = s.dx;
	s.i = -1;
	while (++s.i <= s.stp)
	{
		if ((NDX) >= 0 && (NDX) < v->win_w * v->win_h && (NDX) < v->win_w *
				(a.y + 1) && (NDX) >= v->win_w * a.y && NDX < v->win_w * 1587)
			v->data[NDX] = COLOR;
		a.x += s.xinc;
		s.dy += s.initdy;
		if (s.dy > s.dx)
		{
			s.dx += s.initdx;
			a.y += s.yinc;
		}
	}
}

void			vertical_oblique_segment(t_pt a, t_pt b, t_fv *v)
{
	t_segm_v s;

	s.dx = ABS(b.x - a.x);
	s.dy = ABS(b.y - a.y);
	s.xinc = (b.x > a.x) ? 1 : -1;
	s.yinc = (b.y > a.y) ? 1 : -1;
	(b.x == a.x) ? s.xinc = 0 : 0;
	(b.y == a.y) ? s.yinc = 0 : 0;
	s.initdx = s.dx;
	s.initdy = s.dy;
	s.stp = s.dy;
	s.i = -1;
	while (++s.i <= s.stp)
	{
		if ((NDX) >= 0 && (NDX) < v->win_w * v->win_h && (NDX) < v->win_w *
				(a.y + 1) && (NDX) >= v->win_w * a.y && NDX < v->win_w * 1587)
			v->data[NDX] = COLOR;
		a.y += s.yinc;
		s.dx += s.initdx;
		if (s.dx > s.dy)
		{
			s.dy += s.initdy;
			a.x += s.xinc;
		}
	}
}

void			traceline(t_pt a, t_pt b, t_fv *v)
{
	int tmp;

	if (a.x > b.x && a.y > b.y)
	{
		tmp = a.x;
		a.x = b.x;
		b.x = tmp;
		tmp = a.y;
		a.y = b.y;
		b.y = tmp;
	}
	if (b.x - a.x == 0)
		vertical_oblique_segment(a, b, v);
	else if (b.y - a.y == 0)
		horizontal_oblique_segment(a, b, v);
	else if (ABS(b.x - a.x) >= ABS(b.y - a.y))
		horizontal_oblique_segment(a, b, v);
	else if (ABS(b.x - a.x) < ABS(b.y - a.y))
		vertical_oblique_segment(a, b, v);
}
