/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:35:25 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/17 07:51:28 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

int	ft_distrub(char *buff, char **line, char **cache)
{
	char	*swp;

	if (ft_strchr(buff, '\n') != NULL)
	{
		swp = *line;
		*line = ft_strnjoin(*line, buff, ft_clettercount(buff, '\n'));
		ft_strdel(&swp);
		swp = *cache;
		*cache = ft_strdup(ft_strchr(buff, '\n') + 1);
		ft_strdel(&swp);
		return (1);
	}
	else if (ft_strchr(buff, '\n') == NULL)
	{
		swp = *line;
		*line = ft_strjoin(*line, buff);
		buff[0] = 0;
		ft_strdel(&swp);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*cache;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	if (!head && (head = ft_lstnew("\0", fd)) == NULL)
		return (-1);
	cache = head;
	if (cache->content_size != (size_t)fd)
		cache = ft_lst_nb_chr_n_add(&head, fd);
	*line = ft_strdup("\0");
	if (CC && ft_distrub(CC, line, (char **)&(CC)) == 1)
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_distrub(buff, line, (char **)&(CC)) == 1)
			return (1);
	}
	return ((ft_strlen(*line) != 0) ? 1 : 0);
}
