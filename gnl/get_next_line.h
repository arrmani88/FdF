/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:25:43 by anel-bou          #+#    #+#             */
/*   Updated: 2020/01/19 19:08:45 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 1000
# define CC cache->content

int		get_next_line(const int fd, char **line);

#endif
