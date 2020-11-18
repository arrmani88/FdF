/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 04:31:48 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/19 22:30:52 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		word_counter(char *line)
{
	int i;
	int count;

	i = -1;
	if (!line[0])
		return (0);
	count = (line[0] == ' ') ? 0 : 1;
	while (line[++i])
	{
		if (line[i] == ' ' && line[i + 1] && line[i + 1] != ' ')
			count++;
	}
	return (count);
}

int		set_dimentions_variables(t_fv *v, char *file)
{
	char	*line;
	int		fd;
	int		i;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	if (!(get_next_line(fd, &line)))
		return (-1);
	v->wid = word_counter(line);
	ft_strdel(&line);
	v->len = 1;
	while (get_next_line(fd, &line) == 1 && ++v->len)
		ft_strdel(&line);
	return (0);
}

void	fill_map_tab(t_fv *v)
{
	v->tab[v->i][++v->j] = ft_atoi(&(v->line[v->n]));
	while ((v->line[v->n] && v->line[v->n] >= '0' &&
	v->line[v->n] <= '9') || v->line[v->n] == '-')
		v->n++;
	if (v->line[v->n] == ',')
		while (v->line[v->n] && v->line[v->n] != ' ')
			v->n++;
	while (v->line[v->n] && v->line[v->n] == ' ')
		v->n++;
}

int		allocate_fill_map_tab(t_fv *v, char *file)
{
	if ((v->fd = open(file, O_RDONLY)) == -1)
		return (-1);
	v->tab = (int **)malloc(sizeof(int *) * v->len);
	v->i = -1;
	while (++v->i < v->len)
		v->tab[v->i] = (int *)malloc(sizeof(int) * v->wid);
	if (!(get_next_line(v->fd, &(v->line))))
		return (-1);
	v->i = -1;
	while (++v->i < v->len)
	{
		v->n = 0;
		while (v->line[v->n] && v->line[v->n] == ' ')
			v->n++;
		v->j = -1;
		while (v->line[v->n])
			fill_map_tab(v);
		ft_strdel(&(v->line));
		if (!(get_next_line(v->fd, &(v->line))))
			return (0);
	}
	ft_strdel(&(v->line));
	return (0);
}
