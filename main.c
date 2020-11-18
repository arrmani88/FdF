/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:09:01 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/21 20:16:48 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ISO_ANG 30 * M_PI / 180
#define COLOR 0xFFFF00

void	isometric_view(t_fv v)
{
	t_pt	*nxt;
	int		xi;
	int		yi;

	nxt = v.dupnode->c_next;
	while (v.dupnode)
	{
		while (v.dupnode)
		{
			xi = v.dupnode->x;
			yi = v.dupnode->y;
			v.dupnode->x = (xi - yi) * cos(ISO_ANG);
			v.dupnode->y = (xi + yi) * sin(ISO_ANG) - v.dupnode->z;
			v.dupnode = v.dupnode->b_next;
		}
		v.dupnode = nxt;
		nxt ? nxt = nxt->c_next : 0;
	}
}

void	modify_shape(t_fv *v)
{
	t_pt	head;

	pull_shape(v, &head);
	resize_shape(v);
	(v->iso) ? isometric_view(*v) : 0;
	rotate_x_vec(v);
	rotate_y_vec(v);
	rotate_z_vec(v);
	push_shape(v, &head);
}

void	draw_shape(t_fv *v)
{
	t_pt	*nxt;
	t_pt	*ptr;

	modify_shape(v);
	moove_shape(v);
	ptr = v->dupnode;
	nxt = ptr->c_next;
	while (ptr)
	{
		while (ptr)
		{
			if (ptr->b_next)
				traceline(*ptr, *ptr->b_next, v);
			if (ptr->c_next)
				traceline(*ptr, *ptr->c_next, v);
			ptr = ptr->b_next;
		}
		ptr = nxt;
		nxt ? nxt = nxt->c_next : 0;
	}
}

void	set_vars(t_fv *v)
{
	v->win_w = 2000;
	v->win_h = 1750;
	v->push_x = 0;
	v->push_y = 0;
	v->x_ang = -45;
	v->y_ang = -36.57;
	v->z_ang = 30.57;
	v->zoom = 2;
	v->altt = 1;
	v->iso = 0;
}

int		main(int argc, char **argv)
{
	t_fv	v;

	if (argc == 2 && check_error(argv[1]))
	{
		check_line_alignment(argv[1]);
		set_vars(&v);
		v.co_idf = mlx_init();
		v.win = mlx_new_window(v.co_idf, v.win_w, v.win_h, "FdF");
		v.xpm = mlx_xpm_file_to_image(v.co_idf, "./yons.xpm", &v.w, &v.h);
		v.data = (int *)mlx_get_data_addr(v.xpm, &v.bpp, &v.line_sz, &v.endian);
		v.line_sz = v.win_w;
		if (set_dimentions_variables(&v, argv[1]) == -1 ||
		allocate_fill_map_tab(&v, argv[1]) == -1)
			return (-1);
		v.node = grid_of_nodes(&v);
		v.dupnode = grid_of_nodes(&v);
		center_shape(&v, v.node);
		center_shape(&v, v.dupnode);
		draw_shape(&v);
		mlx_hook(v.win, 2, 0, key_press, &v);
		mlx_put_image_to_window(v.co_idf, v.win, v.xpm, 0, 0);
		mlx_loop(v.co_idf);
	}
	ft_usage();
	return (0);
}
