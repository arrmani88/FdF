/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 23:07:20 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/17 23:10:38 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define RAD(X) X * M_PI / 180

void	rotate_z_vec(t_fv *v)
{
	t_pt	*nxt;
	t_pt	*ptr;
	int		xi;

	ptr = v->dupnode;
	nxt = v->dupnode->c_next;
	while (ptr)
	{
		while (ptr)
		{
			xi = ptr->x;
			ptr->x = ptr->x * cos(RAD(v->z_ang)) - ptr->y * sin(RAD(v->z_ang));
			ptr->y = ptr->y * cos(RAD(v->z_ang)) + xi * sin(RAD(v->z_ang));
			ptr = ptr->b_next;
		}
		ptr = nxt;
		if (nxt)
			nxt = nxt->c_next;
	}
}

void	rotate_x_vec(t_fv *v)
{
	t_pt	*nxt;
	t_pt	*ptr;
	int		yi;
	int		zi;

	ptr = v->dupnode;
	nxt = v->dupnode->c_next;
	while (ptr)
	{
		while (ptr)
		{
			yi = ptr->y;
			ptr->y = ptr->y * cos(RAD(v->x_ang)) + ptr->z * sin(RAD(v->x_ang));
			ptr->z = -yi * sin(RAD(v->x_ang)) + ptr->z * cos(RAD(v->x_ang));
			ptr = ptr->b_next;
		}
		ptr = nxt;
		if (nxt)
			nxt = nxt->c_next;
	}
}

void	rotate_y_vec(t_fv *v)
{
	t_pt	*nxt;
	t_pt	*ptr;
	int		xi;

	ptr = v->dupnode;
	nxt = v->dupnode->c_next;
	while (ptr)
	{
		while (ptr)
		{
			xi = ptr->x;
			ptr->x = ptr->x * cos(RAD(v->y_ang)) + ptr->z * sin(RAD(v->y_ang));
			ptr->z = -ptr->x * sin(RAD(v->y_ang)) + ptr->z * cos(RAD(v->y_ang));
			ptr = ptr->b_next;
		}
		ptr = nxt;
		if (nxt)
			nxt = nxt->c_next;
	}
}
