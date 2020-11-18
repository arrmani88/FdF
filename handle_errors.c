/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:13:45 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/21 21:01:09 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ERR_MSG "Data error: one of the given lines is smaller than the first"

void	ft_usage(void)
{
	ft_putendl("Usage : ./fdf <filename>");
	exit(0);
}

int		check_error(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) <= 0)
	{
		if (get_next_line(fd, &line) == 0)
		{
			ft_putendl("no data file");
			exit(0);
		}
		perror("");
		exit(0);
	}
	ft_strdel(&line);
	return (1);
}

int		calc_line_len(char **line)
{
	int	value;
	int n;

	value = 0;
	n = (*(line)[0] == ' ' ? 1 : 0);
	while ((*line)[n])
	{
		value++;
		while (((*line)[n] && (*line)[n] >= '0' &&
					(*line)[n] <= '9') || (*line)[n] == '-')
			n++;
		if ((*line)[n] == ',')
			while ((*line)[n] && (*line)[n] != ' ')
				n++;
		while ((*line)[n] && (*line)[n] == ' ')
			n++;
	}
	ft_strdel(line);
	return (value);
}

int		check_line_alignment(char *file)
{
	char	*line;
	int		fd;
	int		first_line;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	if (line[0] == 0)
	{
		ft_putendl("the fist line is empty");
		ft_strdel(&line);
		exit(0);
	}
	first_line = calc_line_len(&line);
	while (get_next_line(fd, &line))
	{
		if (first_line > calc_line_len(&line))
		{
			ft_putendl(ERR_MSG);
			exit(0);
		}
	}
	return (1);
}
