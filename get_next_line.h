/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:00:56 by donghwik          #+#    #+#             */
/*   Updated: 2021/02/01 01:11:24 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
#  define OPEN_MAX 100
# endif

typedef	struct		s_node
{
	int				fd;
	struct s_node	*next;
	char			*temp;
}					t_node;

int					set_line(char **line, char **arr, char *buf, int fd);
int					set_line_no_read(char **line, char **arr, int fd);
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
int					glue(char **arr, char *buf, int bufsize, int fd);
int					cut_set(char **arr, int index, char **line, int fd);
int					free_buf_return(int ret, char *buf);
int					line_handler(int fd, char *buf, char **arr, char **line);
#endif
