/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:10:53 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/17 23:09:47 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define XSHAPE_HLF (v->wid * v->zoom) / 2
#define YSHAPE_HLF (v->len * v->zoom) / 2
#define XWIN_HLF v->win_w / 2
#define YWIN_HLF v->win_h / 2

void	pull_shape(t_fv *v, t_pt *head)
{
	t_pt	*nxt;
	t_pt	*ptr;

	ptr = v->dupnode;
	nxt = ptr->c_next;
	while (ptr)
	{
		while (ptr)
		{
			ptr->x = ptr->x - XWIN_HLF;
			ptr->y = ptr->y - YWIN_HLF;
			ptr = ptr->b_next;
		}
		ptr = nxt;
		if (nxt)
			nxt = nxt->c_next;
	}
}

void	push_shape(t_fv *v, t_pt *head)
{
	t_pt	*nxt;
	t_pt	*ptr;

	ptr = v->dupnode;
	nxt = ptr->c_next;
	while (ptr)
	{
		while (ptr)
		{
			ptr->x += XWIN_HLF;
			ptr->y += YWIN_HLF;
			ptr = ptr->b_next;
		}
		ptr = nxt;
		if (nxt)
			nxt = nxt->c_next;
	}
}

void	center_shape(t_fv *v, t_pt *p)
{
	t_pt	*nxt;
	t_pt	*ptr;

	ptr = p;
	nxt = ptr->c_next;
	while (ptr)
	{
		while (ptr)
		{
			ptr->x += (v->win_w / 2) - ((v->wid * v->zoom) / 2);
			ptr->y += (v->win_h / 2) - ((v->len * v->zoom) / 2);
			ptr = ptr->b_next;
		}
		ptr = nxt;
		if (nxt)
			nxt = nxt->c_next;
	}
}

void	moove_shape(t_fv *v)
{
	t_pt	*nxt;
	t_pt	*ptr;

	ptr = v->dupnode;
	nxt = ptr->c_next;
	while (ptr)
	{
		while (ptr)
		{
			ptr->x += v->push_x;
			ptr->y += v->push_y;
			ptr = ptr->b_next;
		}
		ptr = nxt;
		if (nxt)
			nxt = nxt->c_next;
	}
}

void	resize_shape(t_fv *v)
{
	t_pt	*nxt;
	t_pt	*ptr;

	ptr = v->dupnode;
	nxt = ptr->c_next;
	while (ptr)
	{
		while (ptr)
		{
			ptr->y = (ptr->y * v->zoom);
			ptr->x = (ptr->x * v->zoom);
			ptr->z = (ptr->z * v->zoom);
			ptr = ptr->b_next;
		}
		ptr = nxt;
		if (nxt)
			nxt = nxt->c_next;
	}
}
