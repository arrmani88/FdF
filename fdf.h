/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 02:55:41 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/21 20:14:14 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "math.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

typedef struct	s_pt
{
	int			x;
	int			y;
	int			z;
	struct s_pt	*b_next;
	struct s_pt	*c_next;
}				t_pt;

typedef struct	s_tri
{
	t_pt		*a;
	t_pt		*b;
	t_pt		*c;
}				t_tri;

typedef struct	s_segm_v
{
	int			dx;
	int			dy;
	int			stp;
	int			i;
	int			initdy;
	int			initdx;
	int			xinc;
	int			yinc;
}				t_segm_v;

typedef struct	s_fv
{
	t_pt		*node;
	t_pt		*dupnode;
	t_pt		*grid_head;
	t_pt		*line_head;
	t_pt		*prev;
	t_pt		*p;
	float		altt;
	float		z_ang;
	float		x_ang;
	float		y_ang;
	int			**tab;
	int			len;
	int			wid;
	int			zoom;
	int			iso;
	int			bpp;
	int			line_sz;
	int			endian;
	int			*data;
	int			win_w;
	int			win_h;
	int			w;
	int			h;
	int			push_x;
	int			push_y;
	void		*co_idf;
	void		*win;
	void		*xpm;
	int			i;
	int			j;
	int			fd;
	int			n;
	char		*line;
}				t_fv;

void			horizontal_oblique_segment(t_pt a, t_pt b, t_fv *v);
void			vertical_oblique_segment(t_pt a, t_pt b, t_fv *v);
void			traceline(t_pt a, t_pt b, t_fv*v);
int				allocate_fill_map_tab(t_fv *v, char *file);
int				set_dimentions_variables(t_fv *v, char *file);
void			pull_shape(t_fv *v, t_pt *head);
void			push_shape(t_fv *v, t_pt *head);
void			rotate_z_vec(t_fv *v);
void			rotate_x_vec(t_fv *v);
void			rotate_y_vec(t_fv *v);
int				key_press(int key, void *params);
void			draw_shape(t_fv *v);
void			isometric_view(t_fv v);
t_pt			*grid_of_nodes(t_fv *v);
void			modify_shape(t_fv *v);
void			center_shape(t_fv *v, t_pt *ptr);
void			resize_shape(t_fv *v);
void			moove_shape(t_fv *v);
void			get_grid_boards(t_fv *v, t_pt *head);
void			duplicate_node(t_fv *v);
int				check_error(char *file);
void			ft_usage(void);
int				calc_line_len(char **line);
int				check_line_alignment(char *file);

#endif
