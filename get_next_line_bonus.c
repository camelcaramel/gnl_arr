/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:33:47 by donghwik          #+#    #+#             */
/*   Updated: 2021/02/13 15:47:18 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		set_line_no_read(char **line, char **arr, int fd)
{
	unsigned int	index;

	index = 0;
	while (arr[fd][index])
	{
		if (arr[fd][index] == '\n')
		{
			if (cut_set(arr, index, line, fd))
				return (1);
			else
				return (-1);
		}
		index++;
	}
	if (cut_set(arr, index, line, fd))
		return (0);
	return (-1);
}

int		set_line(char **line, char **arr, char *buf, int fd)
{
	unsigned int	index;
	int				bufsize;

	index = 0;
	bufsize = (int)ft_strlen(buf);
	if (!glue(arr, buf, bufsize, fd))
		return (-1);
	while (arr[fd][index])
	{
		if (arr[fd][index] == '\n')
		{
			if (cut_set(arr, index, line, fd))
				return (1);
			else
				return (-1);
		}
		index++;
	}
	return (2);
}

int		line_handler(int fd, char *buf, char **arr, char **line)
{
	int		ret;

	while (1)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (free_buf_return(-1, buf));
		if (ret == 0)
		{
			if (ft_strlen(arr[fd]) == 0)
			{
				if (!(*line = (char *)malloc(sizeof(char))))
					return (free_buf_return(-1, buf));
				*line[0] = '\0';
				return (free_buf_return(0, buf));
			}
			return (free_buf_return(set_line_no_read(line, arr, fd), buf));
		}
		else if (ret > 0)
		{
			buf[ret] = '\0';
			if ((ret = set_line(line, arr, buf, fd)) == 2)
				continue ;
			return (free_buf_return(ret, buf));
		}
	}
}

int		get_next_line(int fd, char **line)
{
	static char		*arr[OPEN_MAX];
	char			*buf;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	return (line_handler(fd, buf, arr, line));
}
