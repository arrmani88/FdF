/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:50:18 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/19 20:00:14 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_codes.h"

void	liberate_grid(t_pt **p)
{
	t_pt	*line_head;
	t_pt	*next;

	while (*p)
	{
		line_head = (*p)->c_next;
		while (*p)
		{
			next = (*p)->b_next;
			ft_memdel((void **)p);
			*p = next;
		}
		*p = line_head;
	}
}

int		libreate_memory(t_fv *v)
{
	int i;
	int j;

	i = -1;
	j = -1;
	mlx_destroy_image(v->co_idf, v->xpm);
	mlx_destroy_window(v->co_idf, v->win);
	liberate_grid(&(v->dupnode));
	liberate_grid(&(v->node));
	while (++i < v->len)
		free(v->tab[i]);
	return (1);
}

void	handle_key_press(int key, t_fv *v)
{
	(key == KEY_P) ? v->z_ang = 0 : 0;
	(key == KEY_P) ? v->x_ang = 0 : 0;
	(key == KEY_P) ? v->y_ang = 0 : 0;
	(key == KEY_PGUP) ? v->altt -= 0.1 : 0;
	(key == KEY_PGDN) ? v->altt += 0.1 : 0;
	(key == KEY_PLS) ? v->zoom++ : 0;
	(key == KEY_MNS) ? v->zoom-- : 0;
	(key == KEY_RIGHT) ? v->push_x += 4 : 0;
	(key == KEY_LEFT) ? v->push_x -= 4 : 0;
	(key == KEY_DOWN) ? v->push_y += 8 : 0;
	(key == KEY_UP) ? v->push_y -= 8 : 0;
	(key == KEY_I) ? v->z_ang = 30.57 : 0;
	(key == KEY_I) ? v->x_ang = -45 : 0;
	(key == KEY_I) ? v->y_ang = -36.57 : 0;
	(key == KEY_Z) ? v->z_ang += 3 : 0;
	(key == KEY_A) ? v->z_ang -= 3 : 0;
	(key == KEY_Y) ? v->y_ang += 3 : 0;
	(key == KEY_H) ? v->y_ang -= 3 : 0;
	(key == KEY_X) ? v->x_ang += 3 : 0;
	(key == KEY_S) ? v->x_ang -= 3 : 0;
}

int		key_press(int key, void *params)
{
	t_fv *v;

	v = (t_fv *)params;
	if (key == KEY_ESC && libreate_memory(v))
		exit(0);
	handle_key_press(key, v);
	v->zoom <= 0 ? v->zoom = 1 : 0;
	mlx_destroy_image(v->co_idf, v->xpm);
	v->xpm = mlx_xpm_file_to_image(v->co_idf, "./yons.xpm", &v->w, &v->h);
	duplicate_node(v);
	draw_shape(v);
	mlx_put_image_to_window(v->co_idf, v->win, v->xpm, 0, 0);
	return (0);
}
