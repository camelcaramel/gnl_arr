/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:33:51 by donghwik          #+#    #+#             */
/*   Updated: 2021/02/01 19:35:28 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char *temp;

	if (s == NULL)
		return (0);
	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

int		cut_set(char **arr, int index, char **line, int fd)
{
	char			*temp;
	char			*node_temp;
	int				i;
	int				len;

	len = (int)ft_strlen(arr[fd]);
	if (!(temp = (char *)malloc(sizeof(char) * (index + 1))))
		return (-1);
	if (!(node_temp = (char *)malloc(sizeof(char) * (len - index))))
	{
		free(temp);
		return (-1);
	}
	i = -1;
	while (++i < index)
		temp[i] = arr[fd][i];
	temp[i++] = '\0';
	*line = temp;
	len = 0;
	while (i < len)
		node_temp[len++] = arr[fd][i++];
	node_temp[len] = '\0';
	temp = arr[fd];
	arr[fd] = node_temp;
	free(temp);
	return (1);
}

int		glue(char **arr, char *buf, int bufsize, int fd)
{
	int				len;
	char			*temp;
	unsigned int	index;
	unsigned int	r_index;
	char			*node_temp;

	len = ft_strlen(arr[fd]);
	if (!(temp = (char *)malloc(sizeof(char) * (len + bufsize + 1))))
		return (-1);
	index = 0;
	r_index = 0;
	while (len > 0 && arr[fd][index])
		temp[r_index++] = arr[fd][index++];
	index = 0;
	while (buf[index])
		temp[r_index++] = buf[index++];
	temp[r_index] = '\0';
	node_temp = arr[fd];
	arr[fd] = temp;
	free(node_temp);
	return (1);
}

int		free_buf_return(int ret, char *buf)
{
	free(buf);
	return (ret);
}
