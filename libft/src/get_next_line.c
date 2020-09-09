/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:41:05 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char			*check_ostatok(char **ostatok, char **line)
{
	char			*n;

	n = NULL;
	if (*ostatok)
	{
		if ((n = ft_strchr(*ostatok, '\n')))
		{
			*n = '\0';
			*line = ft_strdup(*ostatok);
			ft_strcpy(*ostatok, ++n);
		}
		else
		{
			*line = ft_strdup(*ostatok);
			ft_memdel((void **)ostatok);
		}
	}
	else
		*line = ft_strnew(1);
	return (n);
}

static int			read_line(const int fd, char **line, char **ostatok)
{
	char			*n;
	int				byteread;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];

	n = check_ostatok(ostatok, line);
	while (!n && (byteread = read(fd, &buf, BUFF_SIZE)))
	{
		buf[byteread] = '\0';
		if ((n = ft_strchr(buf, '\n')))
		{
			*n = '\0';
			*ostatok = ft_strdup(++n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || byteread < 0)
			return (-1);
		ft_memdel((void **)&tmp);
	}
	if (!*ostatok)
		return (byteread == 0 && !(ft_strlen(*line)) ? 0 : 1);
	return (byteread > 0 || ft_strlen(*line) || ft_strlen(*ostatok) ? 1 : 0);
}

static t_gnl		*new_list(int fd)
{
	t_gnl			*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->ostatok = NULL;
	return (new);
}

static void			ft_tmpdel(t_gnl **alst)
{
	if (!*alst)
		return ;
	free((*alst)->ostatok);
	free((*alst)->next);
	free(*alst);
	*alst = NULL;
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	t_gnl			*pretmp;
	int				otvet;

	if (line == NULL || fd < 0)
		return (-1);
	if (head == NULL)
		head = new_list(fd);
	tmp = head;
	pretmp = NULL;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list(fd);
		pretmp = tmp;
		tmp = tmp->next;
	}
	otvet = read_line(tmp->fd, line, &tmp->ostatok);
	if (otvet == 0 && pretmp)
	{
		pretmp->next = tmp->next;
		ft_tmpdel(&tmp);
	}
	return (otvet);
}
