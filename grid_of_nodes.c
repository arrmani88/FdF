/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_of_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 23:51:05 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/19 18:48:56 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ISO_ANG 30 * M_PI / 180

void	ft_continue(t_fv *v)
{
	while (++v->j < v->wid)
	{
		v->p->c_next = NULL;
		if (v->i >= 1)
		{
			v->prev->c_next = v->p;
			v->prev = v->prev->b_next;
		}
		v->p->x = v->j * v->zoom;
		v->p->y = (v->i) * v->zoom;
		v->p->z = v->tab[v->i][v->j] * v->zoom;
		if (v->j + 1 < v->wid)
		{
			v->p->b_next = (t_pt *)malloc(sizeof(t_pt));
			v->p = v->p->b_next;
		}
	}
}

t_pt	*grid_of_nodes(t_fv *v)
{
	v->i = -1;
	v->line_head = (t_pt *)malloc(sizeof(t_pt));
	v->grid_head = v->line_head;
	v->p = v->line_head;
	while (++v->i < v->len)
	{
		v->j = -1;
		v->i == 0 ? v->p = v->line_head : 0;
		ft_continue(v);
		v->p->b_next = NULL;
		v->prev = v->line_head;
		if (v->i + 1 < v->len)
		{
			v->line_head->c_next = (t_pt *)malloc(sizeof(t_pt));
			v->line_head = v->line_head->c_next;
		}
		v->p = v->line_head;
	}
	return (v->grid_head);
}

void	duplicate_node(t_fv *v)
{
	t_pt	*nxt;
	t_pt	*ptr;
	t_pt	*dpptr;
	t_pt	*dpnxt;

	ptr = v->node;
	nxt = v->node->c_next;
	dpptr = v->dupnode;
	dpnxt = v->dupnode->c_next;
	while (ptr)
	{
		while (ptr)
		{
			dpptr->x = ptr->x;
			dpptr->y = ptr->y;
			dpptr->z = ptr->z * v->altt;
			ptr = ptr->b_next;
			dpptr = dpptr->b_next;
		}
		ptr = nxt;
		dpptr = dpnxt;
		if (nxt)
			nxt = nxt->c_next;
		(dpnxt) ? dpnxt = dpnxt->c_next : 0;
	}
}
